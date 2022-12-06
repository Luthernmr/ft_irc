#include	"../includes/Server.hpp"

int	main(int argc, char** argv)
{
	try
	{
		if (argc != 3)
			throw std::invalid_argument(("Invalid args ./ircserv <port> <password>"));
		Server irc(argv[1], argv[2]);
		irc.start();
		return (0);
	}
	catch(const std::exception& e)
	{
		std::cerr << strerror(errno) << ": " << e.what() << std::endl;
		return (1);
	}
}

// /server add irc localhost/4242 -password=test

// /mode #channel +o nickname 

// :dan!d@localhost <client> ???