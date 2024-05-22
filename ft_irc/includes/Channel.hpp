#pragma once
#include "Server.hpp"
#include "Client.hpp"

class Client;

typedef std::map<std::string, std::pair<Client*, bool> >::const_iterator	ClientLstMapIter;
typedef std::vector<std::string>::const_iterator	InviteVecIter;

class Channel
{
private:
	std::map<std::string, std::pair<Client*, bool> > mClientLstMap;	// map<nickname, pair<Client*, operator right> >
	bool		misInviteOnly;		// boolean for checking invite only option
	bool		mTopicChangeAuth;	// boolean for topic change authority goes for only operators(case false) or all channel users(case true)
	std::string mChannelName;		// channel name
	std::string mTopic;				// channel topic
	std::string mChannelPassword;	// channel password
	size_t		mUserNumLimit;		// maximun number of Clients in channel, default is 0
	std::vector<std::string> mInvitedClients; //invited Clients
public:
	Channel() {};
	Channel(const std::string& channelname);
	~Channel();
	bool isInviteOnly() const;
	bool isChannelFull() const;
	bool isClientCanJoin(const std::string& clientnick) const;
	const std::string& getChName() const;
	const std::string& getChTopic() const;
	const std::string& getChPassword() const;
	Client* getClient(const std::string& username) const;
	int getClientNum() const;
	int getUserNumLimit() const;
	bool getTopicChangeAuth() const;
	const std::map<std::string, std::pair<Client*, bool> >& getClientMap() const;
	std::string getChannelflags() const;

	int isOper(const std::string& clientnick) const;
	void kickClient(const std::string& clientnick);

	void setChPassword(const std::string& newpassword);
	void setChTopic(const std::string& newtopic);
	void setTopicAuth(bool val);
	void setInviteOnly(bool val);
	void setUserNumLimit(int i);
	void setOper(const std::string& clientnick, const bool val);

	void addNewClient(Client* newclient);
	void addInvitedClient(const std::string& clientNick);
	void sendMsg(const std::string& clientname, const std::string& msg); //send Msg to all users join in channel
};
