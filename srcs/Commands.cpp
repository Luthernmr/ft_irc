#include "../includes/Server.hpp"

/*---------------Constructor/Destructor--------------*/

/*---------------------Setters-----------------------*/

/*----------------------Getters---------------------*/

/*-----------------MemberFunctions------------------*/

void	Server::execCommand(Client &client)
{
	std::map<std::string, void (Server::*)(Client &)>::iterator it = _commandMap.find(client.getTokens()[0]);
	if (it != _commandMap.end())
		(this->*(it->second))(client);
}

void	Server::nick(Client &client)
{
	client.setNickname(client.getTokens()[1]);
	if(!client.getAuth())
	{
		client.setIsAuth(-1);
		client.setReply(ERR_WRONGPASSWORD(client.getNickname()));	
	}
	else
		client.setReply(RPL_WELCOME(client.getNickname()));
}

void	Server::pass(Client &client)
{
	std::cout << client.getTokens()[0];
	if (client.getTokens()[1] == _password)
		client.setIsAuth(1);
}

void	Server::cap(Client &client)
{
	(void)client;
}

void	Server::user(Client &client)
{
	client.setUsername(client.getTokens()[1]);
	client.setRealname(client.getTokens()[4]);
}

void	Server::join(Client &client)
{
	if (!_channelMap[client.getTokens()[1]])
	{
		_channelMap[client.getTokens()[1]] = new Channel(client);
		client.setPrefix("@");
		_channelMap[client.getTokens()[1]]->setSymbol("=");
		//client.setReply(RPL_JOIN(client.getNickname(), _channelMap[client.getTokens()[1]]->getName()) + \
		//RPL_TOPIC(client.getNickname(), _channelMap[client.getTokens()[1]]->getName(), _channelMap[client.getTokens()[1]]->getTopic()) + \
		//RPL_NAMEPLY(client.getNickname(), \
		//							 _channelMap[client.getTokens()[1]]->getSymbol(), \
		//							 _channelMap[client.getTokens()[1]]->getName(), \
		//							 _channelMap[client.getTokens()[1]]->membershipList()) + \
		//RPL_ENDOFNAME(client.getNickname(), _channelMap[client.getTokens()[1]]->getName()));
		std::cout << "\n\n\n\n{"<< client.getReply() << "}\n\n\n\n";
	}
	else
	{
		_channelMap[client.getTokens()[1]]->setClientList(client);
		client.setReply(RPL_TOPIC(client.getNickname(), _channelMap[client.getTokens()[1]]->getName(), _channelMap[client.getTokens()[1]]->getTopic()));

	}
}

void	Server::quit(Client &client)
{
	close(client.getFd());
	FD_CLR(client.getFd(), &_clientFds);
	FD_CLR(client.getFd(), &_readFds);
}

void	Server::ping(Client &client)
{
	client.setReply(RPL_PING(client.getTokens()[1]));
}

void	Server::privMsg(Client &client)
{
	(void)client;
	// std::map<int, Client>::iterator it = _clientMap.begin();
	// while (it != _clientMap.end())
	// {
	// 	_clientMap[client.getFd()].getNickname();
	// }
	// _clientFds[client.getNickname()];
	// std::map<int, Client>::iterator it = _clientMap.find(currentFd);
	// client.setReply(PRIVMSG(_clientMap[] ,client.getTokens()[1]));
}
