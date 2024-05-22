#pragma once
#include "Client.hpp"

class Bot : public Client
{
private:

public:
	Bot();
	~Bot();

	void rollTheDice(const std::string& channelName);
};


