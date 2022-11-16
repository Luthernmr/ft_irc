#include	"../includes/Server.hpp"

/*---------------Constructor/Destructor--------------*/

Server::Server(const std::string& port, const std::string& password)
:_port(port), _password(password)
{
	_opt = 1;
}

Server::~Server(){}

/*---------------------Accessors--------------------*/

int		Server::getServerFd(void)
{
	return (_serverFd);
}

/*-----------------MemberFunctions------------------*/

void	Server::start(void)
{
	if ((_serverFd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		throw	std::runtime_error("socket failed");
	if ((setsockopt(_serverFd, SOL_SOCKET,SO_REUSEADDR, &_opt, sizeof(_opt))) < 0)
		throw	std::runtime_error("setsocketopt failed");
    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = INADDR_ANY;
    _address.sin_port = htons(atoi(_port.c_str()));
	if (bind(_serverFd, (struct sockaddr*)&_address, sizeof(_address)) < 0)
		throw	std::runtime_error("bind failed");
	if (listen(_serverFd, 42) < 0)
		throw	std::runtime_error("listen failed");
	int addrlen = sizeof(_address);
	if ((_newSocket = accept(_serverFd, (struct sockaddr*)&_address, (socklen_t *)&addrlen)) < 0)
		throw	std::runtime_error("accept failed");
	std::cout << "connected" << std::endl;
}