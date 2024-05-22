#include "Client.hpp"

Client::Client() :
misRegistered(false),
mNick(""),
mUserName(""),
mRealName(""),
mPassPass(true) {}

Client::Client(const std::string& ip, int socket, int port) :
misRegistered(false),
mNick(""),
mUserName(""),
mRealName(""),
mIP(ip),
mSocket(socket),
mPort(port),
mPassPass(true) {}

Client::~Client() {}

int Client::getSocket() const
{
	return mSocket;
}

bool Client::getReg() const
{
	return misRegistered;
}

std::string& Client::getRecvBuf()
{
	return mRecvBuf;
}

std::string& Client::getSendBuf()
{
	return mSendBuf;
}

const std::string& Client::getIP() const
{
	return mIP;
}

const std::string& Client::getNick() const
{
	return mNick;
}

const std::string& Client::getUserName() const
{
	return mUserName;
}

const int& Client::getPort() const
{
	return mPort;
}

int Client::getJoinChNum() const
{
	return mJoinedChannelMap.size();
}

void Client::setReg()
{
	misRegistered = true;
}

std::string Client::setNick(const std::string& newnick)
{
	std::string& ret = mNick;
	mNick = newnick;
	return ret;
}

void Client::setUserName(const std::string& username)
{
	mUserName = username;
}

void Client::setRealName(const std::string& realname)
{
	mRealName = realname;
}

void Client::setPassTrue()
{
	mPassPass = true;
}

void Client::setPassFalse()
{
	mPassPass = false;
}

bool Client::isClientReady() const
{
	return (mNick != "" && mUserName.size() && mRealName.size() && misRegistered == false && mPassPass);
}

std::vector<std::string> Client::disconnect()
{
	std::vector<std::string> ChList;
	while (mJoinedChannelMap.size())
	{
		JoinedChannelsIter it = mJoinedChannelMap.begin();
		Channel& joinedchannel = *it->second;
		joinedchannel.kickClient(mNick);
		ChList.push_back(joinedchannel.getChName());
		mJoinedChannelMap.erase(it);
	}
	return ChList;
}

void Client::sendMsg(const std::string& msg) const
{
	for (JoinedChannelsIter it = mJoinedChannelMap.begin(); it != mJoinedChannelMap.end(); it++)
		it->second->sendMsg(getNick(), msg);
}

void Client::addNewChannel(Channel& newchannel)
{
	mJoinedChannelMap[newchannel.getChName()] = &newchannel;
}

int Client::deleteChannel(std::string& channelname)
{
	if (mJoinedChannelMap.find(channelname) != mJoinedChannelMap.end())
	{
		mJoinedChannelMap.erase(channelname);
		return 0;
	}
	return 1;
}
