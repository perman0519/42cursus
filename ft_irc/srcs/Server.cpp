#include "Server.hpp"

IrcServer::~IrcServer() {}

IrcServer::IrcServer(int argc, char** argv)
{
	if (argc < 2 || argc > 3)
		throw std::runtime_error("Usage: <server> <port number> <password(optional)>");

	char *endptr;
	mPort = strtol(argv[1], &endptr, 10);
	if (argc == 3)
	{
		mPassword = argv[2];
	}
	std::string endptrStr(endptr);

	if (mPort <= 0 || mPort > 65535 || endptrStr.size())
		throw std::runtime_error("ERROR: invalid mPort number");

	//socket creation
	mServSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (mServSocket == -1)
		throw std::runtime_error("ERROR: socket() failed");
	memset(&mAddr, 0, sizeof(mAddr));
	mAddr.sin_family = AF_INET;
	mAddr.sin_port = htons(mPort);

	//binding
	if (bind(mServSocket, (struct sockaddr*)&mAddr, sizeof(mAddr)) == -1)
		throw std::runtime_error("ERROR: bind() failed");

	//listening
	if (listen(mServSocket, INT_MAX) == -1)
		throw std::runtime_error("ERROR: listen() failed");
	fcntl(mServSocket, F_SETFL, O_NONBLOCK);
}

int IrcServer::getPort() const
{
	return mPort;
}

uintptr_t IrcServer::getSock() const
{
	return mServSocket;
}
