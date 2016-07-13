#include "Room.h"
#include "User.h"
#include "Helper.h"
#include "Protocol.h"
Room::Room(User* admin, std::string name, int questionsNo, int questionTime, int maxUsers, int id)
{
	
	this->_admin = admin;
	this->_name = name;
	this->_id = id;
	this->_questionTime = questionTime;
	this->_questionsNo = questionsNo;
	this->_maxUsers = maxUsers;
	this->_users.push_back(admin); //since admin is also a user
}
bool Room::joinRoom(User* user)
{
	if (_users.size() == _maxUsers)
	{
		return false;
	}
	this->_users.push_back(user);
	return true;
}
void Room::leaveRoom(User* user)
{
	for (int i = 0; i < _users.size(); i++)
	{
		if (_users[i] == user)
			_users.erase(_users.begin() + i);
	}
}
int Room::closeRoom(User* user)
{
	Helper help;
	if (user == _admin) //should work since these are pointers
	{
		int i = 0;
		while (_users.size()>0)
		{
			help.sendData(_users[i]->getSocket(), ROOM_CLOSED);
			leaveRoom(_users[i]);
		}
	}
}
std::vector<User*> Room::getUsers()
{
	return _users;
}
std::string Room::getUsersListMessage()
{
	std::string list = RETURN_USER_LIST;
	list += _users.size();
	list += "##";
	for (int i = 0; i < _users.size(); i++)
	{
		list += _users[i]->getUsername();
		list += "##";
	}
	return list;
}
int Room::getQuestionsNo()
{
	return _questionsNo;
}
int Room::getId()
{
	return _id;
}
std::string Room::getName()
{
	return _name;
}