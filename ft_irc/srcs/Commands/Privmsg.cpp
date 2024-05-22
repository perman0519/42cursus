#include "EventHandler.hpp"

void EventHandler::PRIVMSG()
{
	Client& caller = mClientMap[mCurEvent->ident];
	std::string& clientBuf = caller.getRecvBuf();
	std::vector<std::string> param = split(clientBuf, ' ');
	if (param.size() == 0) {
		sendNumericReply(ERR_NORECIPIENT, caller, 0, " :No recipient given (PRIVMSG)"); //411
		return ;
	}
	std::vector<std::string> nicks = split(param[0], ',');

	if (param.size() == 1) {
		sendNumericReply(ERR_NOTEXTTOSEND, caller, CMD_PRIVMSG, ":No text to send"); //412
		return ;
	}
	if (param.size() > 2 && param[1][0] != ':') {
		sendNumericReply(ERR_NEEDMOREPARAMS, caller, CMD_PRIVMSG, ":Syntax error"); //461
		return ;
	}

	for (size_t i = 0; i < nicks.size(); i++) {
		Client* sendClient = mDefaultChannel.getClient(nicks[i]);
		if (sendClient == NULL && mChannelMap.find(nicks[i]) == mChannelMap.end()) { //find clinet or Channel
			sendNumericReply(ERR_NOSUCHNICK, caller, CMD_PRIVMSG, nicks[i] + " :No such nick/channel"); //401
			continue;
		}
		std::string sendMsg = ":" + caller.getNick() + " PRIVMSG " + nicks[i] + clientBuf.substr(clientBuf.find(' ')) + "\n";
		if (sendClient != NULL) {
			sendClient->getSendBuf() += sendMsg;
			caller.getRecvBuf().clear();
		} else {
			Channel &sendChannel = mChannelMap[nicks[i]];
			if (sendChannel.getClient(caller.getNick()) == NULL)
			{
				sendNumericReply(ERR_CANNOTSENDTOCHAN, caller, CMD_PRIVMSG, ":Cannot send to channel"); //404
				continue ;
			}
			if (*param.rbegin() == ":!roll")
			{
				mBot.rollTheDice(sendChannel.getChName());
				return ;
			}
			sendChannel.sendMsg(caller.getNick(), sendMsg);
		}
	}
}
