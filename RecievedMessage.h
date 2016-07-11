#include <WinSock2.h>
#include <string>
#include <vector>
#include "User.h"
class RecievedMessage{
public:
	RecievedMessage(SOCKET, int);
	RecievedMessage(SOCKET, int, std::vector<std::string>);
	SOCKET getSock();
	User * getUser();
	void setUser(User *);
	int getMessageCode();
	vector<string>& getValues();
private:
	SOCKET _sock;
	User *_user;
	int _messageCode;
	std::vector<std::string> _values; 
};