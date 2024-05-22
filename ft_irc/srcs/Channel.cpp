#include "Channel.hpp"

Channel::Channel(const std::string& channelname) :
misInviteOnly(false),
mTopicChangeAuth(false),
mChannelName(channelname),
mTopic("N/A"),
mChannelPassword(""),
mUserNumLimit(0)
{}

Channel::~Channel()
{
	std::string msg = "Channel " + getChName() + " has destroyed\n";
	sendMsg("", msg);
	mClientLstMap.clear();
}

bool Channel::isInviteOnly() const
{
	return misInviteOnly;
}

bool Channel::isChannelFull() const
{
	if (mUserNumLimit > 0)
	{
		size_t usernum = mClientLstMap.size();
		if (usernum >= mUserNumLimit)
			return true;
	}
	return false;
}

bool Channel::isClientCanJoin(const std::string& clientnick) const
{
	for (InviteVecIter it = mInvitedClients.begin(); it != mInvitedClients.end(); it++)
	{
		if (*it == clientnick)
			return true;
	}
	return false;
}

const std::string& Channel::getChName() const
{
	return mChannelName;
}

const std::string& Channel::getChTopic() const
{
	return mTopic;
}

const std::string& Channel::getChPassword() const
{
	return mChannelPassword;
}

int Channel::getClientNum() const
{
	return mClientLstMap.size();
}

int Channel::getUserNumLimit() const
{
	return mUserNumLimit;
}

bool Channel::getTopicChangeAuth() const
{
	return mTopicChangeAuth;
}

std::string Channel::getChannelflags() const
{
	std::string msg = " +n";
	if (misInviteOnly)
		msg += "i";
	if (mTopicChangeAuth)
		msg += "t";
	if (mUserNumLimit)
	{
		std::stringstream ssInt;
		ssInt << mUserNumLimit;
		msg += "l " + ssInt.str();
	}
	return msg;
}

int Channel::isOper(const std::string& clientnick) const
{
	ClientLstMapIter it = mClientLstMap.find(clientnick);
	if (it == mClientLstMap.end())
	{
		return -1;
	}
	return it->second.second;
}

void Channel::kickClient(const std::string& clientnick)
{
	mClientLstMap.erase(clientnick);

	//INVITE ONLY인 채널에서 KICK당한경우
	if (misInviteOnly == true)
	{
		mInvitedClients.erase(std::remove(mInvitedClients.begin(), mInvitedClients.end(), clientnick), mInvitedClients.end());
	}
}

void Channel::setChPassword(const std::string& newpassword)
{
	mChannelPassword = newpassword;
}

void Channel::setChTopic(const std::string& newtopic)
{
	mTopic = newtopic;
}

void Channel::setInviteOnly(bool val)
{
	misInviteOnly = val;
}

void Channel::setUserNumLimit(int num)
{
	mUserNumLimit = num;
}

void Channel::setTopicAuth(bool val)
{
	mTopicChangeAuth = val;
}

void Channel::setOper(const std::string& clientnick, const bool val)
{
	mClientLstMap[clientnick].second = val;
}

void Channel::addNewClient(Client* newclient)
{
	mClientLstMap[newclient->getNick()] = std::make_pair(newclient, false);
	if (mClientLstMap.size() == 1)
		mClientLstMap.begin()->second.second = true;
}

void Channel::sendMsg(const std::string& clientname, const std::string& msg)
{
	for (ClientLstMapIter it = mClientLstMap.begin(); it != mClientLstMap.end(); it++)
	{
		if (it->second.first->getNick() == clientname)
			continue;
		it->second.first->getSendBuf() += msg;
	}
}

Client* Channel::getClient(const std::string& clientnick) const
{
	ClientLstMapIter it = mClientLstMap.find(clientnick);
	if (it == mClientLstMap.end())
	{
		return NULL; //찾는 유저가 채널에 없음
	}
	return it->second.first;
}

void Channel::addInvitedClient(const std::string& clientNick)
{
	if (mInvitedClients.end() == find(mInvitedClients.begin(), mInvitedClients.end(), clientNick))
		mInvitedClients.push_back(clientNick);
}

const std::map<std::string, std::pair<Client*, bool> >& Channel::getClientMap() const
{
	return mClientLstMap;
}
