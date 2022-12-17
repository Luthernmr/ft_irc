#pragma 	once

#include	"Utils.hpp"
#include	"Client.hpp"
using		namespace std;

class Client;

class Channel
{
	private:
		string				_name;
		string				_password;
		string				_topic;
		string				_symbol;
		string				_mode;
		vector<int>			_clientFd;
		map<string, int>	_nameFd;
		map<string, int>	_bannedClientFd;
		vector<string>		_invitedList;

	public:
		Channel();
		~Channel();

		string			getTopic(void);
		string			getName(void);
		string			getSymbol(void);
		string			getMode(void);
		vector<int>		&getFdVector(void);
		vector<string>	&getInvitedList(void);
		int				getNameFd(string name);

		void			setTopic(string topic);
		void			setSymbol(string symbol);
		void			setName(string name);
		void			setMode(string mode);
		void			setInvited(string name);
		void			setPassword(string password);
		void			setNameFd(string name, int fd);
		void			setFd(int fd);

		bool			clientIsBanned(Client &client);
		bool			clientIsOnChan(Client &client);
		void			eraseClient(Client &client);
};