#include "Room.h"

Room::Room(User* admin, string name, int questionsNo, int questionTime, int maxUsers, int id)
{
	this->_admin = admin;
	this->_name = name;
	this->_id = id;
	this->_questionTime = questionTime;
	this->_questionsNo = questionsNo;
	this->_maxUsers = maxUsers;
}
bool Room::joinRoom(User*)
{

}
void Room::leaveRoom(User*)
{

}
int Room::closeRoom(User*)
{

}
Vector<std::User*> _users Room::getUsers()
{

}
string Room::getUsersListMessage()
{
	
}
int Room::getQuestionsNo()
{
	return _questionsNo;
}
int Room::getId()
{
	return _id;
}
string Room::getName()
{
	return _name;
}