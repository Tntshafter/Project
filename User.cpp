#include "User.h"
#include "Helper.h"
#include <iostream>
#include <string>
#include "Protocol.h"
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
	a.sendData(this->_sock, msg); //WRONG - unless it includes message code and appereantly it does
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
	_currRoom->leaveRoom(this);
	this->_currRoom = nullptr;
	//teacher said its like this. i thought otherwise but whatever
}
bool User::createRoom(int questionsNo, std::string strings, int questionTime, int maxUsers, int id)
{
	
	Helper help;
	if (this->_currRoom != nullptr || maxUsers < 2 || questionsNo < 4 || questionTime < 2 ) //necessary checks
	{
		help.sendData(this->_sock, CREATE_ROOM_FAIL);
		return false;
	}
	_currRoom = new Room(this, strings, questionsNo, questionTime, maxUsers, id);
	help.sendData(this->_sock, CREATE_ROOM_SUCCESS);
	return true;
}
bool User::joinRoom(Room* room)
{
	Helper help;
	if (this->_currRoom != nullptr)
	{
		help.sendData(_sock, JOIN_ROOM_FAIL);
		return false;
	}
	help.sendData(_sock, JOIN_ROOM_SUCCESS);
	return this->joinRoom(room);
}
void User::leaveRoom()
{
	_currRoom->leaveRoom(this); 
	this->_currRoom = nullptr;
	Helper help;
	help.sendData(_sock, LEAVE_ROOM_SUCCESS);
}
int User::closeRoom()
{
	_currRoom->closeRoom(this); 
	this->_currRoom = nullptr;
}
bool User::leaveGame()
{
	_currGame->leaveGame(this);
}