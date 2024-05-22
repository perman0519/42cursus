#include "EventHandler.hpp"

void EventHandler::TOPIC()
{
	Client& caller = mClientMap[mCurEvent->ident];
	std::string& buffer = caller.getRecvBuf();
	std::vector<std::string> splitVec = split(buffer, ':');
	if (buffer.empty() || splitVec.size() > 2)
	{
		sendNumericReply(ERR_NEEDMOREPARAMS, caller, CMD_TOPIC, ":Syntax error\nUsage: TOPIC <channel> [:<topic>]");
		return ;
	}
	std::string channelname = trim(splitVec[0]);
	// 채널명이 채널명 형식을 위배하거나 해당 채널을 찾을 수 없을 경우 예외처리
	if (!isValidChName(channelname) || mChannelMap.find(channelname) == mChannelMap.end())
	{
		sendNumericReply(ERR_NOSUCHCHANNEL, caller, CMD_TOPIC, ":No such channel");
		return ;
	}
	Channel& targetCh = mChannelMap[channelname];
	if (splitVec.size() == 1)
	{
		if (targetCh.getChTopic() == "N/A")
			sendNumericReply(RPL_NOTOPIC, caller, 0, " :No topic is set");
		else
			sendNumericReply(RPL_TOPIC, caller, 0, targetCh.getChTopic());
		return ;
	}
	std::string newTopic = splitVec[1];
	splitVec.clear();
	int isoper = targetCh.isOper(caller.getNick());
	if (isoper < 0)
	{
		sendNumericReply(ERR_NOTONCHANNEL, caller, CMD_TOPIC, targetCh.getChName() + " :You're not on that channel");
		return ;
	}
	if (isoper == 0 && targetCh.getTopicChangeAuth())
	{
		sendNumericReply(ERR_CHANOPRIVSNEEDED, caller, 0, targetCh.getChName() + " :You're not channel operator");
		return ;
	}
	targetCh.setChTopic(newTopic);
	sendNumericReply(RPL_TOPIC, caller, CMD_TOPIC, targetCh.getChName() + ' ' + targetCh.getChTopic());
	std::string successMsg = ':' + caller.getNick() + '!' + caller.getUserName() + '@' + caller.getIP() + " TOPIC " + targetCh.getChName() + " :" + newTopic + '\n';
	targetCh.sendMsg("", successMsg);
}
