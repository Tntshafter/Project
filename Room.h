#include <string>
#include <vector>
class Room{
public:
	Room(User*, string, int, int, int, int);
	bool joinRoom(User*);
	void leaveRoom(User*);
	int closeRoom(User*);
	std::vector<User*> getUsers();
	string getUsersListMessage();
	int getQuestionsNo();
	int getId();
	string getName();
	
	string getUsersAsString(vector<User*>, User*);
	int sendMessage(string);
	int sendMessage(User*, string);



private:
	std::vector<User*> _users;
	User* _admin; 
	int _maxUsers;
	int _questionTime;
	int _id;
	int _questionsNo;
	string _name;
	

};