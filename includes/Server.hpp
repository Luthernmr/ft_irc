#pragma		once

#include	"../includes/Utils.hpp"
#include	"../includes/Client.hpp"

class Client;

class Server
{
private:
	std::string					_port;
	std::string					_password;
	int							_serverFd;
	int							_opt;
	struct fd_set				_clientFds;
	struct fd_set				_readFds;
	struct fd_set				_writeFds;
	struct sockaddr_in			_address;
	int							_addrLen;
	struct timeval				_timeout;
	std::map<int, Client>		_clientMap;
	std::map<int, void *>		_serverMap;
	char						_buffer[BUFF_SIZE];
	std::vector<std::string>	_tokens;
	std::vector<std::string>::iterator _It;

public:
	Server(const std::string& port, const std::string& password);
	~Server();

	void	start(void);
	void	socketInit(void);
	void	acceptNewClient(void);
	void	handleMsg(int currentFd);
};