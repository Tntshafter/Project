#include <iostream>
#include <string>
#include <vector>
//#include "User.h"
class Room{
public:
	Room(User*, std::string, int, int, int, int);
	bool joinRoom(User*);
	void leaveRoom(User*);
	int closeRoom(User*);
	std::vector<User*> getUsers();
	std::string getUsersListMessage();
	int getQuestionsNo();
	int getId();
	std::string getName();
	
	int sendMessage(std::string);
	int sendMessage(User*, std::string);



private:
	std::vector<User*> _users;
	User* _admin; 
	int _maxUsers;
	int _questionTime;
	int _id;
	int _questionsNo;
	string _name;
	

};