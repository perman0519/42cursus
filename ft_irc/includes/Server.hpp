#pragma once
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>
#include <string>
#include <exception>
#include <map>
#include <vector>
#include <sstream>

class IrcServer
{
private:
	int mServSocket;		// server socket fd
	int mPort;				// port number
	std::string mPassword;	// server access password
	sockaddr_in mAddr;
public:
	IrcServer(int argc, char** argv);
	~IrcServer();
	int getPort() const;
	uintptr_t getSock() const;
};
