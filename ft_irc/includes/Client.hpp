#pragma once
#include "Server.hpp"
#include "Channel.hpp"

class Server;
class Channel;

typedef std::map<std::string, Channel*>::const_iterator	JoinedChannelsIter;

class Client
{
protected:
	std::map<std::string, Channel*> mJoinedChannelMap; //클라이언트가 조인한 채널 맵
	bool misRegistered;						// 서버에 접속한 적 있는지 확인
	std::string mNick;						// 중복 불가능; 예: muyaho
	std::string	mUserName;					// 중복 가능; 예: Yuseung Kim
	std::string	mRealName;					// 중복 가능; 예: Yuseung Kim
	std::string	mIP;						// IP 주소: 10.11.7.1
	int			mSocket;					// accept를 통해 리턴된 소켓 fd
	int			mPort;						// port 번호
	std::string mRecvBuf;					// client에서 recv받은 데이터 저장소 JOIN CHANNELNAME
	std::string mSendBuf;					// client fd로 send할 데이터 저장소
	bool		mPassPass;					//password를 맞게 입력해야 true

public:
	Client();
	Client(const std::string& ip, int socket, int port);
	~Client();
	int getSocket() const;
	bool getReg() const;
	std::string& getRecvBuf();
	std::string& getSendBuf();
	const std::string& getIP() const;
	const std::string& getNick() const;
	const std::string& getUserName() const;
	const int& getPort() const;
	int getJoinChNum() const;

	void setReg();
	std::string setNick(const std::string& newnick);	// NICK command return the oldnick
	void setUserName(const std::string& username);		// set username
	void setRealName(const std::string& username);		// set username
	void setPassTrue();
	void setPassFalse();

	bool isClientReady() const;

	std::vector<std::string> disconnect();

	void sendMsg(const std::string& msg) const;			// call the sendmsg member func on every channels in JoinedChannlsVec
	void addNewChannel(Channel& newchannel);		// push_back newChannel
	int deleteChannel(std::string& channelname);	// PART, KICK command
};
