#include "EventHandler.hpp"

void EventHandler::USER()
{
	Client& caller = mClientMap[mCurEvent->ident];
	std::string& buffer = caller.getRecvBuf();
	std::vector<std::string> splitVec = split(buffer, ':');
	if (buffer.empty() || splitVec.size() == 1)
	{
		sendNumericReply(ERR_NEEDMOREPARAMS, caller, CMD_USER, ":Syntax error\nUsage: USER <username> <hostname> <servername> :<realname>");
		return ;
	}
	std::string realname = splitVec[1];
	splitVec = split(splitVec[0], ' ');
	if (splitVec.size() != 3)
	{
		sendNumericReply(ERR_NEEDMOREPARAMS, caller, CMD_USER, ":Syntax error\nUsage: USER <username> <hostname> <servername> :<realname>");
		return ;
	}
	if (caller.getReg() == true)
	{
		sendNumericReply(ERR_ALREADYREGISTRED, caller, CMD_USER, ":User already registered");
		return ;
	}
	caller.setUserName(splitVec[0]);
	caller.setRealName(realname);
	if (caller.isClientReady())
	{
		sendNumericReply(RPL_WELCOME, caller, 0, " :Welcome to irserv!");
		caller.getSendBuf() += welcome();
		mDefaultChannel.addNewClient(&caller);
		caller.addNewChannel(mDefaultChannel);
		caller.setReg();
		std::string msg = ":*!" + caller.getUserName() + "@ircserv NICK " + caller.getNick() + '\n';
		caller.sendMsg(msg);
	}
	else if (mPassword.size() && caller.getNick().size())
	{
		std::string errmsg = ":ircserv :ircserv :server password is required\n";
		send(mCurEvent->ident, errmsg.c_str(), errmsg.size(), 0);
		disconnectClient();
	}
}
