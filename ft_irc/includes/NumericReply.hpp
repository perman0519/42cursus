#pragma once

/*
형식 : [:prefix] <numeric> <target> <command> :<message>

[:prefix] : 이 부분은 선택적입니다. 메시지의 출처를 나타내는 서버 이름이나 닉네임이 포함됩니다. 예를 들어 :irc.example.com입니다.
<numeric> : 3자리 숫자 코드로, 메시지의 유형을 나타냅니다. 예를 들어 001은 환영 메시지, 433은 닉네임 중복 에러 등입니다.
<target> : 메시지의 대상입니다. 닉네임, 채널 이름 또는 *(모든 사용자)일 수 있습니다.
<command> : 메시지와 관련된 명령어입니다. 예를 들어 NICK, JOIN 등입니다.
:<message> : 메시지 본문입니다.

예시 1:irc.example.com 001 YourNickname :Welcome to the Internet Relay Network YourNickname!~username@host
예시 2:irc.example.com 433 YourNickname NICK :Nickname is already in use
*/


#define PREFIX ":ircserv "
// 공용
#define RPL_WELCOME "001"			// "Welcome to the Internet Relay Network <nick>!<user>@<host>"
#define RPL_NOTOPIC "331"	// <channel> :No topic is set
#define RPL_TOPIC "332"	// <channel> :<topic>
#define ERR_NEEDMOREPARAMS "461"	// <command> :Syntax error
#define ERR_CHANOPRIVSNEEDED "482" // "<channel> :You're not channel operator"
#define ERR_NOTONCHANNEL "442" //클라이언트가 특정 채널에 참여하지 않은 상태에서 채널 관련 명령을 시도할 때 사용
#define ERR_NOSUCHCHANNEL "403"	// <channel name> :No such channel (invaild channel)
#define ERR_ALREADYREGISTRED "462" // 이미 서버에 등록했는데 다시 JOIN 하였을때
#define ERR_NOSUCHNICK "401" // <nickname> :No such nick/channel

// JOIN CMD
#define ERR_INVITEONLYCHAN "473"	// <channel> :Cannot join channel (+i)
#define ERR_CHANNELISFULL "471"	// <channel> :Cannot join channel (+l)
#define ERR_BADCHANNELKEY "475"	// <channel> :Cannot join channel (+l)
#define ERR_USERONCHANNEL "443"	// "<user> <channel> :is already on channel"

// NICK CMD
#define ERR_NONICKNAMEGIVEN "431" // ":No nickname given"
#define ERR_NICKNAMEINUSE "433" // "<nick> :Nickname is already in use"

// KICK CMD
#define ERR_BADCHANMASK "476" //클라이언트가 채널명 규칙에 위배된 채널명을 사용하여 채널을 식별하려고 할 때 발생 O
#define ERR_USERNOTINCHANNEL "441" //클라이언트가 특정 채널에 속한 사용자를 찾을 수 없을 때 발생 O

// PRIVMSG CMD
#define ERR_NORECIPIENT "411" // :No recipient given (<command>)
#define ERR_NOTEXTTOSEND "412" // :No text to send
#define ERR_CANNOTSENDTOCHAN "404" // <channel name> :Cannot send to channel

// PRIVMSG #channnelname

//PING & PONG CMD
#define ERR_NOORIGIN "409" // "":No origin specified" PING or PONG message missing the originator parameter which is required since these commands must work without valid prefixes.
#define ERR_NOSUCHSERVER "402" // "<server name> :No such server" Used to indicate the server name given currently doesn't exist.

// INVITE CMD
#define RPL_INVITING "341" // "<channel> <nick>"

// MODE CMD
#define RPL_CHANNELMODEIS "324" // "<channel> <mode> <mode params>"
#define ERR_UNKNOWNMODE "472" // ":Unknown MODE flag"
#define ERR_KEYSET "467" // "<channel> :Channel key already set"

#define RPL_NAMREPLY "353"
#define RPL_ENDOFNAMES "366"

//PASS CMD
#define  ERR_PASSWDMISMATCH "464"
