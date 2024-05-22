#include "EventHandler.hpp"

void EventHandler::NICK()
{
	Client &caller = mClientMap[mCurEvent->ident];		// find a caller target
	std::string& buffer = caller.getRecvBuf();			// get the command string buffer
	if (buffer.empty())
	{
		sendNumericReply(ERR_NONICKNAMEGIVEN, caller, CMD_NICK, " :No nickname given");
		return ;
	}
	for (ClientMapIter it = mClientMap.begin(); it != mClientMap.end(); it++)
	{
		if (it->second.getNick() == buffer) // new nickname already exists
		{
			sendNumericReply(ERR_NICKNAMEINUSE, caller, CMD_NICK, buffer + " :Nickname is already in use");
			return ;
		}
	}
	std::string prevnick = caller.setNick(buffer);
	if (caller.isClientReady())
	{
		sendNumericReply(RPL_WELCOME, caller, 0, " :Welcome to irserv!");
		caller.getSendBuf() += welcome();
		mDefaultChannel.addNewClient(&caller);
		caller.addNewChannel(mDefaultChannel);
		caller.setReg();
	}
	if (caller.getReg())
	{
		std::string msg = ':' + prevnick + '!' + caller.getUserName() + "@ircserv NICK " + caller.getNick() + '\n';
		caller.getSendBuf() += msg;
		caller.sendMsg(msg);
	}
	else if (mPassword.size() && caller.getUserName().size())
	{
		std::string errmsg = ":ircserv :ircserv :server password is required\n";
		send(mCurEvent->ident, errmsg.c_str(), errmsg.size(), 0);
		disconnectClient();
	}
}
