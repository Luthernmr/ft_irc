#include	"../../includes/Server.hpp"
using		namespace std;

void	Server::mode(Client &client)
{
	if (client.getTokens().size() > 2)
	{
		if ((client.getTokens()[2].compare("+i")) == 0)
			_channelMap[client.getTokens()[1]]->setModeI("+i");
		if ((client.getTokens()[2].compare("+k")) == 0)
		{
			_channelMap[client.getTokens()[1]]->setModeK("+k");
			if (client.getTokens().size() > 3)
			{
				_channelMap[client.getTokens()[1]]->setPassword(client.getTokens()[3]);
				client.setReply(RPL_MODE(client.getNickname(),client.getTokens()[1], _channelMap[client.getTokens()[1]]->getModeK()));
			}
		}
	}
}