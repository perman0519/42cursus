#include "EventHandler.hpp"

void EventHandler::KICK()
{
	Client& caller = mClientMap[mCurEvent->ident];
	std::string& buffer = caller.getRecvBuf();

	//buffer에서 채널명만을 분리
	std::string::size_type pos = buffer.find(' ');
	if (pos == std::string::npos)
	{
		sendNumericReply(ERR_NEEDMOREPARAMS, caller, CMD_KICK, ":Not enough parameters");
		return ;
	}
	std::string channel = buffer.substr(0, pos);
	buffer = trim(buffer.substr(pos + 1));

	//channelName이 규칙에 맞게 들어오는지 확인
	if (isValidChName(channel) == false)
	{
		sendNumericReply(ERR_BADCHANMASK, caller, CMD_KICK, ":Bad Channel Mask");
		return ;
	}

	//channel객체를 찾는 작업
	ChannelMapIter it = mChannelMap.find(channel);
	if (it == mChannelMap.end())
	{
		sendNumericReply(ERR_NOSUCHCHANNEL, caller, 0, channel + " :No such channel");
		return ;
	}

	//target client nick 추출
	std::string targetClientNick = buffer;
	pos = buffer.find(' ');
	if (pos != std::string::npos)
	{
		targetClientNick = buffer.substr(0, pos);
		buffer = trim(buffer.substr(pos + 1));
	}
	else
	{
		buffer = caller.getNick();
	}

	//target client가 서버에 있는지 확인
	Client *targetClient = mDefaultChannel.getClient(targetClientNick);
	if (targetClient == NULL)
	{
		sendNumericReply(ERR_NOSUCHNICK, caller, 0, targetClientNick + " :No such nick or channel name");
		return ;
	}


	//targetClient가 caller가 작업하려는 해당채널에 있는지 확인
	Channel& targetCh = it->second;
	if (targetCh.getClient(caller.getNick()) == NULL)
	{
		sendNumericReply(ERR_NOTONCHANNEL, caller, CMD_KICK, ":You're not on that channel");
		return ;
	}

	//target client가 채널에 있는지 확인
	targetClient = targetCh.getClient(targetClientNick);
	if (targetClient == NULL)
	{
		sendNumericReply(ERR_USERNOTINCHANNEL, caller, CMD_KICK, ":They aren't on that channel");
		return ;
	}

	//caller가 operator인지 확인
	if (!targetCh.isOper(caller.getNick()))
	{
		sendNumericReply(ERR_CHANOPRIVSNEEDED, caller, 0, targetCh.getChName() + " :You're not channel operator");
		return ;
	}


	//완료메시지 송신
	std::string msg = ":" + caller.getNick() + '!' + caller.getUserName() + '@' + caller.getIP() + " KICK " + targetCh.getChName() + ' ' + targetClient->getNick() + " " + buffer + '\n';
	targetCh.sendMsg("", msg);
	std::cout << "KICK MSG: " << msg;

	//실제로 kick하는 작업
	targetCh.kickClient(targetClientNick);
	targetClient->deleteChannel(channel);

}
