#include "Room.h"
#include "User.h"
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
	//check if user is admin!
}
std::vector<User*> Room::getUsers()
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