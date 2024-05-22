#include "Server.hpp"
#include "EventHandler.hpp"

int main(int argc, char** argv) {
	if (argc < 2 || argc > 3) 
	{
		std::cerr << "Usage: " << argv[0] << " <port number> <password(optional)>" << std::endl;
		return 1;
	}
	try
	{
		IrcServer server(argc, argv);
		EventHandler events(server.getSock());
		if (argc == 3)
		{
			events.setPass(argv[2]);
		}
		else
		{
			events.setPass("");
		}
		events.addNewEvent(server.getSock(), EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
		std::cout << "echo server started" << std::endl;

		while (1) 
		{
			events.handleEvents();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

}
