#include "EventHandler.hpp"

void	EventHandler::INVITE()
{
	Client& caller = mClientMap[mCurEvent->ident];
	std::string& clientBuf = caller.getRecvBuf();
	std::vector<std::string> param = split(clientBuf, ' ');

	if (param.size() != 2) {
		sendNumericReply(ERR_NEEDMOREPARAMS, caller, CMD_INVITE, ":Syntax error"); //461
		return ;
	}
	Client* invitingClient = mDefaultChannel.getClient(param[0]);
	if (invitingClient == NULL) {
		sendNumericReply(ERR_NOSUCHNICK, caller, CMD_INVITE, param[0] + " :No such nick/channel"); //412
		return ;
	}

	if (caller.getNick() == invitingClient->getNick())
		return ;
	else
	{
		if (mChannelMap.find(param[1]) == mChannelMap.end())
		{
			sendNumericReply(ERR_NOSUCHCHANNEL, caller, CMD_INVITE, param[1] + " :No such channel"); //412
			return ;
		}
		Channel& targetCh = mChannelMap[param[1]];
		if (targetCh.isInviteOnly() && targetCh.isOper(caller.getNick()) == false)
		{
			sendNumericReply(ERR_CHANOPRIVSNEEDED, caller, CMD_TOPIC, targetCh.getChName() + " :You're not channel operator");
			return ;
		}
		targetCh.addInvitedClient(invitingClient->getNick());
		caller.getSendBuf() += ":" + invitingClient->getNick() + " 341 " + caller.getNick() + " " + invitingClient->getNick() + " " + param[1] + "\n";
		invitingClient->getSendBuf() += ":" + caller.getNick() + " INVITE " + invitingClient->getNick() + " " + param[1] + "\n";
	}
}
