#include "EventHandler.hpp"

void EventHandler::PING()
{
	Client& caller = mClientMap[mCurEvent->ident];
	std::string& clientBuf = caller.getRecvBuf();
	std::vector<std::string> param = split(clientBuf, ' ');

	if (clientBuf.size() == 0) {
		sendNumericReply(ERR_NOORIGIN, caller, CMD_PING, caller.getNick() + " :No origin specified"); //412
		return ;
	}
	if (param.size() > 2 && param[0][0] != ':') {
		sendNumericReply(ERR_NOSUCHSERVER, caller, CMD_PING, clientBuf + " :No such server"); //461
		return ;
	}
	if (clientBuf[0] == ':')
		caller.getSendBuf() += ":ircserv PONG ircserv " + clientBuf + "\n";
	else
		caller.getSendBuf() += ":ircserv PONG ircserv :" + clientBuf + "\n";
}
