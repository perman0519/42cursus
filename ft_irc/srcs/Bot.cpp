#include "Bot.hpp"

Bot::Bot() : Client("BOT", 0, 0)
{
	misRegistered = true;
	mNick = "BOT";
	mUserName = "BOT";
	mRealName = "0x42";
	mPassPass = true;
}

Bot::~Bot() {}

void Bot::rollTheDice(const std::string& channelName)
{
	Channel* targetch = mJoinedChannelMap[channelName];
	std::srand((unsigned int)std::clock());
	char random_value = (std::rand() % 6) + 1 + '0';
	std::string msg = ":BOT PRIVMSG " + channelName + " :Random value is: ";
	msg += random_value;
	targetch->sendMsg(mNick, msg + '\n');
}
