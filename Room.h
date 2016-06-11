#include <string>
#include <vector>

class Room{
public:
	Room(User*, string, int, int, int, int);
	bool joinRoom(User*);
	void leaveRoom(User*);
	int closeRoom(User*);
	Vector<std::User*> _users getUsers();
	string getUsersListMessage();
	int getQuestionsNo();
	int getId();
	string getName();
	
	string getUsersAsString(vector<User*>, User*);
	sendMessage(string);
	sendMessage(User*, string);



private:
	//Vector<std::User*> _users;
	User _admin; //User needs to be created
	int _maxUsers;
	int _questionTime;
	int _id;
	int _questionsNo;
	string _name;
	

};