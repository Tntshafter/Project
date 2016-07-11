#include "RecievedMessage.h"
#include <WinSock2.h>
RecievedMessage::RecievedMessage(SOCKET sock , int type)
{
	this->_sock = sock;
	this->_messageCode = type;
}
RecievedMessage::RecievedMessage(SOCKET sock, int type, std::vector<std::string>values)
{
	this->_sock = sock;
	this->_messageCode = type;
	this->_values = values;
}
SOCKET RecievedMessage::getSock()
{
	return _sock;
}
User * RecievedMessage::getUser()
{
	return _user;
}
void RecievedMessage::setUser(User * user)
{
	this->_user = user;
}
int RecievedMessage::getMessageCode()
{
	return this->_messageCode;
}
vector<string>& RecievedMessage::getValues()
{
	return this->getValues;
}