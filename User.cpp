#include "User.h"
#include "Helper.h"
User::User(std::string username, SOCKET sock)
{
	this->_username = username;
	this->_sock = sock;
	this->_currRoom = nullptr;
	this->_currGame = nullptr;
}
void User::send(std::string msg)
{
	Helper a;
	a.sendData(this->_sock, msg); //WRONG - unless it includes message code
}
std::string User::getUsername()
{
	return this->_username;
}
SOCKET User::getSocket()
{
	return this->_sock;
}
Room* User::getRoom()
{
	this->_currRoom;
}
Game* User::getGame()
{
	this->_currGame;
}
void User::setGame(Game* game)
{
	this->_currGame = game;
}
void User::clearRoom()
{
	//later
}
bool User::createRoom(int a, std::string string , int b, int c , int d)
{
	Helper a;
	if (this->_currRoom != nullptr)
	{
		a.sendData(this->_sock, msg);
		return false;
	}
	_currRoom = new Room(this, string, a, b, c, d);
}
bool User::joinRoom(Room* room)
{
	if (this->_currRoom != nullptr) return false;
	return this->joinRoom(room);
	//send message of success or failure
}
void User::leaveRoom()
{
	_currRoom->leaveRoom(this); //i cant do like this
	this->_currRoom = nullptr;

}
int User::closeRoom()
{
	_currRoom->closeRoom(this); //so how do i do it?
	this->_currRoom = nullptr;
}
bool User::leaveGame()
{
	_currGame->leaveGame(this);
}