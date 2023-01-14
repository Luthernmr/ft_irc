# 🌐 ft_irc

Here is the **ft_irc** project wroted by [acroisie](https://github.com/acroisie) and I.

The goal of this project is to achieve a basic **irc server** in C++.

## The rules:

* Manage multiple connections without fork
* Use `poll()` or equivalent (we use `select()`) to manage multiple clients interaction
* Set socket to non-blocking mode
* Authentify by nickname and password
* Manage channel gestion
* Get operator status/commands

---

## To connect to the server, simply use Weechat and follow these steps :

### Launch the server  
```bash
 Make && ./ircserv <port> <password>
```

### Add the server  on Weechat
```bash
/server add <server_name> <localhost>/<port> -password=<password>
```
### Connect to server  
```bash
/connect <server_name>
  
You are now connected to the server!
```
### You can join channels and more
```bash
/join #channel_name

/topic <topic_name>

/msg <name>

/notice #channel_name

/mode <+o> <name> #mode list : +o, -o, +i, -i, +k, -k;

/kick <name>

/ban <name>

/invite <name>

/nick <new_nickname>

/leave
```
## 💬 Enjoy your stay on our server !
