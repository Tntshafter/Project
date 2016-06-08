#include <WinSock2.h>
#include <string>
#include <vector>
class RecievedMessage{
public:



private:
	SOCKET _sock;
	//User _user;
	int _messageCode;
	//vector<std::string> _values; error: vector is not a template(?)
};