#include "EventHandler.hpp"

void EventHandler::PASS()
{
	Client& caller = mClientMap[mCurEvent->ident];
	std::string& buffer = caller.getRecvBuf();
	if (buffer.empty())
	{
		sendNumericReply(ERR_NEEDMOREPARAMS, caller, CMD_PASS, " :Syntax error\nUsage: PASS <password>");
		return ;
	}
	if (caller.getReg() == true)
	{
		sendNumericReply(ERR_ALREADYREGISTRED, caller, CMD_PASS, " :You may not reregister");
		return ;
	}
	if (mPassword != buffer) //비밀번호가 다른경우
	{
		std::string errmsg = ":ircserv 464 PASS :Password incorrect for ircserv";
		send(mCurEvent->ident, errmsg.c_str(), errmsg.size(), 0);
		disconnectClient();
		return ;
	}
	else //PASS는 NICK, USER보다 반드시 선행되어야한다
	{
		caller.setPassTrue();
		caller.setNick("");
		caller.setUserName("");
	}
}
