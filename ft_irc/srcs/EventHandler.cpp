#include "EventHandler.hpp"

EventHandler::EventHandler(uintptr_t serversock) :
mServerSocket(serversock),
mDefaultChannel("default")
{
	mBot = Bot();
	mkq = kqueue();
	if (mkq < 0)
		throw std::runtime_error("ERROR: kqueue() failed");
}

EventHandler::~EventHandler() {}

void EventHandler::addNewEvent(uintptr_t ident, int16_t filter, uint16_t flags, uint32_t fflags, intptr_t data, void *udata)
{
	struct kevent newEvent;

	EV_SET(&newEvent, ident, filter, flags, fflags, data, udata);
	mEventVec.push_back(newEvent);
}

void EventHandler::setPass(const std::string& pass)
{
	mPassword = pass;
}


void EventHandler::handleEvents()
{
	int mEvent = kevent(mkq, &mEventVec[0], mEventVec.size(), mKenventLst, EVENT_NUM, NULL);
	if (mEvent == -1)
		throw std::runtime_error("ERROR: kevent() failed");

	mEventVec.clear();

	for (int i = 0; i < mEvent; i++)
	{
		mCurEvent = &mKenventLst[i];
		uintptr_t curIdent = mCurEvent->ident;

		if (mCurEvent->flags & EV_ERROR)
			handleError();
		else if (mCurEvent->filter == EVFILT_READ)
		{
			if (curIdent == mServerSocket)
				acceptNewClient();
			else if (mClientMap.find(curIdent) != mClientMap.end())
				recvFromClient();						// receve data from client, parse it, and addNewEvent if needed
		}
		else if (mCurEvent->filter == EVFILT_WRITE)
			sendToClient();								// find target Client, send it.
	}
}

void EventHandler::acceptNewClient()
{
	struct sockaddr_in clientAddr;
	socklen_t clientAddrLen = sizeof(clientAddr);
	memset(&clientAddr, 0, clientAddrLen);
	int clientSocket = accept(mServerSocket, (sockaddr*)&clientAddr, &clientAddrLen);
	if (clientSocket < 0)
	{
		std::cerr << "ERROR: client accept() failed" << std::endl;
		return ;
	}

	std::string clientIP = inet_ntoa(clientAddr.sin_addr);
	int clientPort = ntohs(clientAddr.sin_port);

	std::cout << "Accept new client\nIP: " << clientIP << ", port: " << clientPort << std::endl;
	fcntl(clientSocket, F_SETFL, O_NONBLOCK);

	Client newClient(clientIP, clientSocket, clientPort);
	if (mPassword != "")
		newClient.setPassFalse();
	mClientMap[clientSocket] = newClient;
	addNewEvent(clientSocket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, &mClientMap[clientSocket]);
	addNewEvent(clientSocket, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, &mClientMap[clientSocket]);
}

void EventHandler::recvFromClient()
{
	char buf[1024];
	ssize_t ret = recv(mCurEvent->ident, buf, sizeof(buf) - 1, 0);

	if (ret <= 0)
	{
		if (ret < 0)
			std::cerr << "ERROR: client recv() failed" << std::endl;
		disconnectClient();
		return ;
	}
	buf[ret] = '\0';
	Client& client = mClientMap[mCurEvent->ident];
	std::string& clientBuf = client.getRecvBuf();
	clientBuf += buf;
	std::vector<std::string> completelineVec;
	std::string::size_type pos = clientBuf.find('\n');
	while (pos != std::string::npos)
	{
		completelineVec.push_back(clientBuf.substr(0, pos));
		clientBuf = clientBuf.substr(pos + 1);
		pos = clientBuf.find('\n');
	}
	std::string tempBuf;
	if (clientBuf.size())
		tempBuf = clientBuf;
	while (completelineVec.size())
	{
		std::string& targetline = *completelineVec.begin();
		if (*(targetline.rbegin()) == '\r')
			targetline = targetline.substr(0, targetline.size() - 1);
		std::cout << client.getNick() << ": [" << targetline << "]\n";
		int isCmd = isCommand(targetline);
		if (isCmd && (client.getReg() == true || isCmd <= CMD_PASS))
		{
			std::string::size_type pos = targetline.find(' ');
			if (pos == std::string::npos)
				targetline.clear();
			else
			{
				targetline = targetline.substr(pos + 1);
				targetline = trim(targetline);
			}
			clientBuf = targetline;
			execCmd(isCmd);
		}
		completelineVec.erase(completelineVec.begin());
		clientBuf.clear();
	}
	if (tempBuf.size())
		clientBuf = tempBuf;
}

void EventHandler::sendToClient()
{
	ClientMapIter it = mClientMap.find(mCurEvent->ident);
	std::string& buffer = it->second.getSendBuf();
	size_t res = 0;
	if (buffer.size())
		res = send(mCurEvent->ident, buffer.c_str(), buffer.size(), 0);
	if (res < 0)
		disconnectClient();
	if (res < buffer.size())
		buffer = buffer.substr(res);
	else
		buffer.clear();
}

void EventHandler::handleError()
{
	if (mCurEvent->ident == mServerSocket)
		throw std::runtime_error("ERROR: server kevent error");
	else
	{
		std::cerr << "client socket error\n";
		disconnectClient();
	}
}

void EventHandler::disconnectClient()
{
	std::cout << mClientMap[mCurEvent->ident].getIP() << " disconnected" << std::endl;
	Client& target = mClientMap[mCurEvent->ident];
	std::vector<std::string> joinedCh = target.disconnect();
	if (joinedCh.size())
		scanChannels(target.getNick(), joinedCh);
	close(mCurEvent->ident);
	mClientMap.erase(mCurEvent->ident);
}

void EventHandler::scanChannels(const std::string& targetname, std::vector<std::string>& channels)
{
	while(channels.size())
	{
		std::string& channelname = *channels.begin();
		Channel& targetCh = mChannelMap[channelname];
		if (targetCh.getClientNum() == 0)
			mChannelMap.erase(channelname);
		else
			sendNumericReply(ERR_NOTONCHANNEL, targetCh, 0, targetname + " has left the channel");
		channels.erase(channels.begin());
	}
}

int EventHandler::isCommand(std::string& clientbuf) const
{
	std::string cmdarr[] = {"NICK", "USER", "PASS", "JOIN", "PRIVMSG", "PING", "KICK", "TOPIC", "MODE", "INVITE"};
	if (clientbuf.empty())
		return 0;
	std::string::size_type pos = clientbuf.find(' ');
	std::string cmd = clientbuf;
	if (pos != std::string::npos)
		cmd = clientbuf.substr(0, pos);
	for (int i = 0; i < CMDS_NUM; i++)
	{
		if (cmdarr[i] == cmd)
			return (i + 1);
	}
	return 0;
}

void	EventHandler::execCmd(int isCmd)
{
	void	(EventHandler::*fcnPtr[CMDS_NUM])() =
	{
		&EventHandler::NICK,
		&EventHandler::USER,
		&EventHandler::PASS,
		&EventHandler::JOIN,
		&EventHandler::PRIVMSG,
		&EventHandler::PING,
		&EventHandler::KICK,
		&EventHandler::TOPIC,
		&EventHandler::MODE,
		&EventHandler::INVITE
	};
	(this->*fcnPtr[isCmd - 1])();
}

bool EventHandler::isValidChName(const std::string& chname) const
{
	std::string prefix = "&#+!";
	for (size_t i = 0; i < prefix.size(); i++)
	{
		if (prefix[i] == chname[0])
			return true;
	}
	return false;
}

void EventHandler::sendNumericReply(const std::string& codestr, Client& target, int CMD, const std::string& msg)
{
	std::string reply;
	std::string targetname = target.getNick();

	if (codestr.size())
		reply = PREFIX + codestr + ' ' + targetname + ' ' + getCommand(CMD) + msg + '\n';
	else
		reply = PREFIX + targetname + ' ' + getCommand(CMD) + msg + '\n';
	target.getSendBuf() += reply;
	std::cout << "server send to ["<< targetname << "]: " << reply << std::endl;
}

void EventHandler::sendNumericReply(const std::string& codestr, Channel& target, int CMD, const std::string& msg)
{
	std::string reply;
	std::string targetname = target.getChName();
	if (CMD == CMD_MODE)
		targetname = mClientMap[mCurEvent->ident].getNick() + ' ' + target.getChName();

	if (codestr.size())
		reply = PREFIX + codestr + ' ' + targetname + ' ' + getCommand(CMD) + msg + '\n';
	else
		reply = PREFIX + targetname + ' ' + getCommand(CMD) + msg + '\n';
	target.sendMsg("", reply);
	std::cout << "server send to CH["<< targetname << "]: " << reply << std::endl;
}
