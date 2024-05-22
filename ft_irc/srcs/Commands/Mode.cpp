#include "EventHandler.hpp"

void EventHandler::MODE()
{
	Client& caller = mClientMap[mCurEvent->ident];
	std::string& buffer = caller.getRecvBuf();

	if (caller.getJoinChNum() == 1)
		return ;
	if (buffer.empty()) // 들어온 인자가 존재하지 않을 때
	{
		sendNumericReply(ERR_NEEDMOREPARAMS, caller, CMD_MODE, " :Syntax error\nUsage: MODE <channel> *( ( \"-\" / \"+\" ) *<itkol> *<modeparams> )");
		return ;
	}
	std::vector<std::string> splitBufVec = split(buffer, ' ');
	ChannelMapIter it = mChannelMap.find(*splitBufVec.begin()); // 첫번째 인자인 channelname 가져오기
	if (it == mChannelMap.end()) // 만약 채널명에 해당되는 채널이 없을 때
	{
		sendNumericReply(ERR_NOSUCHCHANNEL, caller, CMD_MODE, splitBufVec[0] + " :No such channel");
		return ;
	}
	Channel& targetCh = it->second; // 타겟 채널 설정
	if (splitBufVec.size() == 1)
	{
		sendNumericReply(RPL_CHANNELMODEIS, caller, 0, targetCh.getChName() + targetCh.getChannelflags());
		return ;
	}
	if (targetCh.isOper(caller.getNick()) == false) // 만약 caller가 해당 채널의 오퍼레이터가 아닐 경우
	{
		sendNumericReply(ERR_CHANOPRIVSNEEDED, caller, 0, targetCh.getChName() + " :You're not channel operator");
		return ;
	}
	splitBufVec.erase(splitBufVec.begin()); // 채널 설정 완료했으니 vector에서 지우기
	std::string msg = "";
	std::pair<std::string, std::string> optargs; // <+, - 옵션들>, <옵션 인자들>
	while (splitBufVec.size())
	{
		optargs.first.clear();
		std::string& arg = *splitBufVec.begin();
		if (arg.front() == '+') // + mode options
		{
			arg = arg.substr(1);
			if (arg.front() == '-' || arg.find_first_not_of("tkoli-+") != std::string::npos)
			{
				sendNumericReply(ERR_UNKNOWNMODE, caller, 0, &arg[arg.find_first_not_of("tkoli")]);
				return ;
			}
			optargs.first += '+';
			while (arg.size())
			{
				if (arg.front() == '-')
					break ;
				handleModeArgP(optargs, targetCh, splitBufVec, arg.front());
				arg = arg.substr(1);
			}
			if (optargs.first.size() == 1)
				optargs.first.clear();
		}
		if (arg.front() == '-') // - mode opetions
		{
			arg = arg.substr(1);
			if (arg.front() == '+' || arg.find_first_not_of("tkoli+-") != std::string::npos)
			{
				sendNumericReply(ERR_UNKNOWNMODE, caller, 0, &arg[arg.find_first_not_of("tkoli")]);
				return ;
			}
			optargs.first += '-';
			while (arg.size())
			{
				if (arg.front() == '+')
					break;
				handleModeArgM(optargs, targetCh, splitBufVec, arg.front());
				arg = arg.substr(1);
			}
			if (optargs.first.size() == 1)
				optargs.first.clear();
		}
		if (arg.size() && arg.front() != '+' && arg.front() != '-')
		{
			sendNumericReply(ERR_UNKNOWNMODE, caller, 0, arg);
			splitBufVec.erase(splitBufVec.begin());
		}
		if (splitBufVec.front().empty())
			splitBufVec.erase(splitBufVec.begin());
		msg += optargs.first;
	}
	if (msg.size())
	{
		msg += optargs.second;
		sendNumericReply(RPL_CHANNELMODEIS, targetCh, CMD_MODE, msg);
	}
}

void EventHandler::handleModeArgP(std::pair<std::string, std::string>& msg, Channel& targetCh, std::vector<std::string>& bufVec, const char mode)
{
	Client& caller = mClientMap[mCurEvent->ident];
	std::string targetarg = "";

	if (mode == 'o')
	{
		if (bufVec.size() < 2)
			return ;
		targetarg = bufVec[1];
		if (targetCh.getClient(targetarg) == NULL)
		{
			sendNumericReply(ERR_NOSUCHNICK, caller, CMD_MODE, targetarg + " :No such nick");
			bufVec.erase(bufVec.begin() + 1);
			return ;
		}
		if (targetCh.isOper(targetarg) == true)
			return ;
		targetCh.setOper(targetarg, true);
		bufVec.erase(bufVec.begin() + 1);
	}
	else if (mode == 'k')
	{
		if (bufVec.size() < 2)
		return ;
		targetarg = bufVec[1];
		if (targetCh.getChPassword().size())
		{
			sendNumericReply(ERR_KEYSET, caller, CMD_MODE, targetCh.getChName() + " :Channel key already set");
			bufVec.erase(bufVec.begin() + 1);
			return ;
		}
		targetCh.setChPassword(targetarg);
		bufVec.erase(bufVec.begin() + 1);
	}
	else if (mode == 'l')
	{
		if (bufVec.size() < 2)
			return ;
		targetarg = bufVec[1];
		char* endptr;
		long num = strtol(targetarg.c_str(), &endptr, 10);
		std::string endptrstr(endptr);

		if (num < 1 || num > INT_MAX || endptrstr.size())
		{
			return ;
			bufVec.erase(bufVec.begin() + 1);
		}
		targetCh.setUserNumLimit(num);
		bufVec.erase(bufVec.begin() + 1);
	}
	else if (mode == 'i')
	{
		if (targetCh.isInviteOnly() == true)
			return ;
		targetCh.setInviteOnly(true);
	}
	else if (mode == 't')
	{
		if (targetCh.getTopicChangeAuth() == true)
			return ;
		targetCh.setTopicAuth(true);
	}
	msg.first += mode;
	if (targetarg.size())
		msg.second += ' ' + targetarg;
}

void EventHandler::handleModeArgM(std::pair<std::string, std::string>& msg, Channel& targetCh, std::vector<std::string>& bufVec, const char mode)
{
	Client& caller = mClientMap[mCurEvent->ident];
	std::string targetarg = "";

	if (mode == 'o')
	{
		if (bufVec.size() < 2)
			return ;
		targetarg = bufVec[1];
		if (targetCh.getClient(targetarg) == NULL)
		{
			sendNumericReply(ERR_NOSUCHNICK, caller, CMD_MODE, targetarg + " :No such nick");
			bufVec.erase(bufVec.begin() + 1);
			return ;
		}
		if (targetCh.isOper(targetarg) == false)
			return ;
		targetCh.setOper(targetarg, false);
		bufVec.erase(bufVec.begin() + 1);
	}
	else if (mode == 'k')
	{
		if (targetCh.getChPassword().empty())
			return ;
		targetCh.setChPassword("");
	}
	else if (mode == 'l')
	{
		if (targetCh.getUserNumLimit() == 0)
			return ;
		targetCh.setUserNumLimit(0);
	}
	else if (mode == 'i')
	{
		if (targetCh.isInviteOnly() == false)
			return ;
		targetCh.setInviteOnly(false);
	}
	else if (mode == 't')
	{
		if (targetCh.getTopicChangeAuth() == false)
			return ;
		targetCh.setTopicAuth(false);
	}
	msg.first += mode;
	if (targetarg.size())
		msg.second += ' ' + targetarg;
}
