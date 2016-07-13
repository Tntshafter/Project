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
	vector<string> getPersonalStatus(string);//did not find use for this function. - there were also no instructions for this one.
	int InsertNewGame();
	bool updateGameStatus(int);
	bool addAnswerToPlayer(int, string, int, string, bool, int);
	DataBase& operator=(DataBase arg); //copy operator to initialize databases in Game class
private:
	sqlite3 * db; //had to add this. impossible without
	static int callbackCount(void*, int, char**, char**); //counting the amount of lines in t_players_answers
	static int callbackQuestions(void*, int, char**, char**);
	static int callbackBestScores(void*, int, char**, char**);
	static int callbackCountPersonalStatus(void*, int, char**, char**); //did not find use for this function. 
	static int callbackExists(void*, int, char**, char**); //added for function "isUsernameExists"
	static int callbackGetGameID(void*, int, char**, char**);//added for "insertNewGame" return value
	static int callbackLoginCheck(void*, int, char**, char**); //added for "isUserAndPassMatch
};