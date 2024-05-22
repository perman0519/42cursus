#pragma once
#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "NumericReply.hpp"
#include "utils.hpp"
#include "Bot.hpp"

#define EVENT_NUM 42
#define CMDS_NUM 11

enum CMDS
{
	CMD_NICK = 1,
	CMD_USER,
	CMD_PASS,
	CMD_JOIN,
	CMD_PRIVMSG,
	CMD_PING,
	CMD_KICK,
	CMD_TOPIC,
	CMD_MODE,
	CMD_INVITE,
};

class IrcServer;
class Channel;
class Client;
class Bot;

typedef std::map<int, Client>::iterator				ClientMapIter;
typedef std::map<std::string, Channel>::iterator	ChannelMapIter;

class EventHandler
{
private:
	int mkq;								// kq 의 fd번호
	uintptr_t mServerSocket;				// IrcServer의 socket fd값
	std::string mPassword;					// server access password
	struct kevent mKenventLst[EVENT_NUM];	// kevnet함수를 통해 채워지는 처리해야할 이벤트들의 배열
	std::vector<struct kevent> mEventVec;	// kqueue 이벤트 목록
	struct kevent* mCurEvent;				// 현재 처리중인 이벤트

	std::map<int, Client> mClientMap;		// map<socket fd, class Client>
	std::map<std::string, Channel> mChannelMap;	// map<channelname, class Channel>
	Channel mDefaultChannel;
	Bot mBot;

public:
	EventHandler(uintptr_t serversock);
	~EventHandler();
	void setPass(const std::string& pass);
	void addNewEvent(uintptr_t ident, int16_t filter, uint16_t flags, uint32_t fflags, intptr_t data, void *udata);
	void handleEvents();			// 코어 함수 kevent를 통해 모든 입출력과 통신들을 처리해준다

	void acceptNewClient();			// 새로운 클라이언트 연결을 처리해주는 함수
	void recvFromClient();			// 클라이언트에게서 데이터를 받은 상황, 명령어가 와야 하며 그것을 처리해준다.
	void sendToClient();			// COMMAND 수행 끝나고 클라이언트에게 보내야 할 데이터(numeric replies 등) 보내주는 함수

	void handleError();				// 오류 발생시 처리해주는 함수, 서버오류면 서버 종료, 클라이언트 오류면 해당 클라이언트 disconnect
	void disconnectClient();
	void scanChannels(const std::string& targetname, std::vector<std::string>& channels);			// 비어있는 채널 발견시 채널 삭제

	int isCommand(std::string& clientbuf) const;	// curEvent의 std::string clientbuf를 참조해 현재 들어온 신호가 어떤 명령어인지 필터해주는 함수
	void execCmd(int cmd);	// isCommand의 리턴값을 매개변수로 받아 멤버 함수 포인터를 활용해 대응되는 함수를 실행시켜준다

	bool isValidChName(const std::string& chname) const;	// 유효한 채널명인지 확인

	void NICK();
	void JOIN();
	void USER();
	void PRIVMSG();
	void PING();
	void KICK();
	void INVITE();
	void TOPIC();
	void MODE();
	void PASS();
	void NAMES(const std::string& chName);

	void handleModeArgP(std::pair<std::string, std::string>& msg, Channel& targetCh, std::vector<std::string>& bufVec, const char mode);
	void handleModeArgM(std::pair<std::string, std::string>& msg, Channel& targetCh, std::vector<std::string>& bufVec, const char mode);

	void sendNumericReply(const std::string& codestr, Client& target, int CMD, const std::string& msg);
	void sendNumericReply(const std::string& codestr, Channel& target, int CMD, const std::string& msg); // MODE 명령어 등
};
