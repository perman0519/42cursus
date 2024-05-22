#include "EventHandler.hpp"

void EventHandler::NAMES(const std::string& chName)
{
	Client& caller = mClientMap[mCurEvent->ident];
	std::string msg = " :";
	Channel& ch = (mChannelMap.find(chName))->second;
	for (ClientLstMapIter it = ch.getClientMap().begin(); it != ch.getClientMap().end(); it++)
	{
		if (it->second.second)
			msg += "@" + it->second.first->getNick();
		else
			msg += it->second.first->getNick();
		msg += " ";
	}
	sendNumericReply(RPL_NAMREPLY, caller, 0, "= " + chName + msg);
	sendNumericReply(RPL_ENDOFNAMES, caller, 0, chName + " :End of /NAMES list.");
}
