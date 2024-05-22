#include "EventHandler.hpp"

void EventHandler::JOIN()
{
	Client& caller = mClientMap[mCurEvent->ident];
	std::string& buffer = caller.getRecvBuf();

	if (buffer.empty()) // 들어온 인자가 존재하지 않을 때
	{
		sendNumericReply(ERR_NEEDMOREPARAMS, caller, CMD_JOIN, " :Syntax error\nUsage: JOIN <channelname> <channelpassword(optional)>");
		return;
	}

	std::vector<std::string> bufVec = split(buffer, ' ');
	std::string channelname = bufVec[0], channelpassword = "";
	if (bufVec.size() == 2)
	{
		channelpassword = bufVec[1];
	}

	if (!isValidChName(channelname)) // 채널명이 채널명 형식을 위배할 경우 예외처리
	{
		sendNumericReply(ERR_NOSUCHCHANNEL, caller, CMD_JOIN, " :No such channel");
		return ;
	}

	ChannelMapIter it = mChannelMap.find(channelname); //채널이터레이터
	// 해당하는 채널명이 없을 시 새로 생성해준다.
	if (it == mChannelMap.end())
	{
		mChannelMap[channelname] = Channel(channelname);
		it = mChannelMap.find(channelname);
	}
	Channel& targetch = it->second;

	if (targetch.getClient(caller.getNick()))
	{
		sendNumericReply(ERR_USERONCHANNEL, caller, CMD_JOIN, targetch.getChName() + " :is already on channel");
		return ;
	}
	// 채널 비밀번호가 틀렸을 때
	if (targetch.getChPassword().size() && targetch.getChPassword() != channelpassword)
	{
		sendNumericReply(ERR_BADCHANNELKEY, caller, 0, targetch.getChName() + " :Bad channel key");
		return ;
	}

	// invite-only 채널일 때
	if (targetch.isInviteOnly() && targetch.isClientCanJoin(caller.getNick()) == false)
	{
		sendNumericReply(ERR_INVITEONLYCHAN, caller, 0, targetch.getChName() + " :Invite only channel");
		return ;
	}

	// 채널에 유저가 꽉 찼을때
	if (targetch.isChannelFull())
	{
		sendNumericReply(ERR_CHANNELISFULL, caller, CMD_JOIN, " :Channel is full");
		return ;
	}

	targetch.addNewClient(&caller);	// 실제로 채널에 클라이언트 추가해주기
	caller.addNewChannel(targetch);	// 클라이언트객체에 현재 들어가있는 채널 추가해주기
	mBot.addNewChannel(targetch);	// 봇에 현재 들어가있는 채널 추가해주기
	// :nickname!username@hostmask JOIN :#channel
	std::string msg = ":" + caller.getNick() + '!' + caller.getUserName() + '@' + caller.getIP() + " JOIN :" + channelname + '\n';
	targetch.sendMsg("", msg);
	NAMES(channelname);
}
