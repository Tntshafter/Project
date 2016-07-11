#include <string>
#include <iostream>
#include "Question.h"
#include "sqlite3.h"
using namespace std;
class DataBase
{
public:
	DataBase();
	~DataBase();
	bool isUserExists(string );
	bool addNewUser(string, string, string);
	bool isUserAndPassMatch(string, string);
	vector<Question*> initQuestions(int);
	vector<string> getBestScores();
	vector<string> getPersonalStatus(string);
	int InsertNewGame();
	bool updateGameStatus(int);
	bool addAnswerToPlayer(int, string, int, string, bool, int);
private:
	sqlite3 * db; //had to add this. impossible without
	static int callbackCount(void*, int, char**, char**);
	static int callbackQuestions(void*, int, char**, char**);
	static int callbackBestScores(void*, int, char**, char**);
	static int callbackCountPersonalStatus(void*, int, char**, char**);
};