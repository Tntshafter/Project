#include "DataBase.h"
#include "sqlite3.h"
#include "Protocol.h"
#include <map>
DataBase::DataBase()
{
	int rc;
	rc = sqlite3_open(DB_NAME, &db);
	if (rc)
	{
		throw SQL_OPEN_EXCEPTION;
	}
}

DataBase::~DataBase()
{
	sqlite3_close(db);
}
bool DataBase::isUserExists(string username)
{
	string command = USER_EXISTS_COMMAND + username +"'"+ FINISH_SQL_COMMAND;
	char ** err;
	bool *exists;
	int rc = sqlite3_exec(db,command.c_str(),callbackExists,exists,err);
	return *exists;
}
bool DataBase::addNewUser(string username, string password, string email)
{
	string command = INSERT_NEW_USER_COMMAND+username+"','"+password+"','"+email+"'"+FINISH_SQL_COMMAND_2;
	char ** err;
	int rc = sqlite3_exec(db, command.c_str(), nullptr, nullptr, err);
	if (rc != SQLITE_OK) return false; //unsuccessfull operation for reasons.
	else return true;
}
bool DataBase::isUserAndPassMatch(string username , string password)
{
	string command = CHECK_LOGIN_COMMAND + username +"'"+ FINISH_SQL_COMMAND;
	char ** err;
	string * pass = new string(password);
	int rc = sqlite3_exec(db, command.c_str(), callbackLoginCheck, pass, err);
	if (rc != SQLITE_OK) return false; //unsuccessfull operation for reasons.
	if (pass->compare("true") == 0) return true; //callback returned true
	else return false;
}
vector<Question*> DataBase::initQuestions(int number)
{
	//collect ALL questions - and THEN remove the un-needed amount
	string command = INIT_QUESTIONS_COMMAND;
	char ** err;
	vector<Question*> init;
	string **data = new string*[INIT_QUESTIONS_SIZE];
	int rc = sqlite3_exec(db, command.c_str(), callbackQuestions, data, err);
	for (int i = 0; i < INIT_QUESTIONS_SIZE/6; i++) //every question is 6 data lines
	{
		Question * buffer = new Question(stoi(*data[i]), *data[i+1], *data[i+2], *data[i+3], *data[i+4], *data[i+5]);//where every line is a different column value
		init.push_back(buffer);
	}
	delete(data); //delete the strig form the memory
	return init;
}
vector<string> DataBase::getBestScores()
{
	//step 1: get the amount of lines in t_players_answers
	//step 2: proccess the data and return results
	//step 3: ???
	//step 4: profit
	string command = COUNT_ANSWERS_COMMAND;
	char ** err;
	int *count;
	*count = 0;
	command = BEST_SCORES_COMMAND;
	int rc = sqlite3_exec(db, command.c_str(), callbackCount, count, err); //got the line amount
	string **data = new string*[*count];
	int rc = sqlite3_exec(db, command.c_str(), callbackBestScores,data , err);
	//now processing the data:
	string datas[6];
	int currgameID = 0;
	map<string,std::pair<int,int>> currResults; //a username holds the score of the current game <int game_id, int score>
	map<string, int> highest; //the overall highest scores per username
	for (int i = 0; i < *count / 6; i++) //every answer is 6 data lines
	{
		//checking every game separately and collecting the highest scores. all correct answer count as score (time 60-time is the score)
		datas[0] = *data[i];
		datas[1] = *data[i+1];
		datas[2] = *data[i+2];
		datas[3] = *data[i+3];
		datas[4] = *data[i+4];
		datas[5] = *data[i+5];
		currgameID = stoi(datas[0]);
		if (datas[4].compare("1") == 0) //a username cant play two games at once (i think) so it should work
		{
			std::pair<int, int> values = currResults[datas[1]];
			if (values.first != stoi(datas[0]) )//if the data about the previous game is finished AND the score is higher than the one saved, we save in the highest scores.
		}
	}
	//cannot fail here, not checking if error occurred.
}
vector<string> DataBase::getPersonalStatus(string)
{

}
int DataBase::InsertNewGame()
{
	string command = INSERT_NEW_GAME_COMMAND;
	char ** err;
	int rc = sqlite3_exec(db, command.c_str(), nullptr, nullptr, err);
	string command = INSERT_NEW_GAME_COMMAND;
	char ** err;
	int *game_id;
	int rc = sqlite3_exec(db, command.c_str(), callbackGetGameID, game_id, err);
	return *game_id;
}
bool DataBase::updateGameStatus(int game_id)
{
	string command = GAME_UPDATE_COMMAND + to_string(game_id) + FINISH_SQL_COMMAND;
	char ** err;
	int rc = sqlite3_exec(db, command.c_str(), nullptr, nullptr, err);
	if (rc != SQLITE_OK) return false; //casual error check
	else return true;
}
bool DataBase::addAnswerToPlayer(int game_id, string username , int question_id, string answer , bool is_correct, int time)
{
	string command = NEW_ANSWER_COMMAND + to_string(game_id) + ",'" + username + "','" + answer + "'," + to_string((int)is_correct) + "," + to_string(time);
	char ** err;
	int rc = sqlite3_exec(db, command.c_str(), nullptr, nullptr, err);
	if (rc != SQLITE_OK)
	{
		return false; //error occurred
	}
	return true;
}
int DataBase::callbackCount(void* count, int argc, char**argv, char**azColName)
{
	int * retr = (int*)count;
	if (argv[0] == NULL )
	{
		*retr = atoi(argv[1]);
	}
	else
	{
		*retr = atoi(argv[0]);
	}
	//now let me explain what i just did here: 
	/*
	since we used COUNT there ir only one line that is returned. but since every line is returned as the column name (azColName)
	and the value of the column (argv). yet, the first line is "callback function called, where argv represents a NULL. so to 
	prevent errors, i had to choose the one that is NOT null - and because of the shortage of time, i could not test which line is
	correct so i checked both of them, just in case. Better safe than sorry!
	*/
	return 0;
}
int DataBase::callbackQuestions(void* retr, int argc, char**argv, char**azColName)
{
	if (argc < (INIT_QUESTIONS_SIZE-1)*QUESTION_DATA_LINES) return -1; //something went wrong in reading the questions form the db.
	//since every column represents the data in a different line - every question is 6 lines.
	string ** retrs = (string**)retr;
	for (int i = 0; i < argc; i++)
	{
		retrs[i] = new string(argv[i]);
	}
	return 0;
}
int DataBase::callbackBestScores(void* retr, int argc, char**argv, char**azColName)
{
	//just copying the results to the void* parameter
	string ** retrs = (string**)retr;
	for (int i = 0; i < argc; i++)
	{
		retrs[i] = new string(argv[i]);
	}
	return 0;
}
int DataBase::callbackCountPersonalStatus(void*, int argc, char**argv, char**azColName)
{

}
int DataBase::callbackExists(void* exists, int argc, char**argv, char**azColName)
{
	bool *flag = (bool*)exists;
	if (argc > 1) *flag = true; //if any parameters were selected in the scan
	else *flag = false;
	return 0;
}
int DataBase::callbackGetGameID(void * id, int argc, char** argv, char**azColName)
{
	int *ids = (int*)id; 
	*ids = stoi(string(argv[argc - 1]),nullptr,10); //last line where the latest id is
	return 0;
}
int callbackLoginCheck(void* pass, int argc, char** argv , char** azColName)
{
	string *retr = (string *)pass;
	string returnedValue = string(argv[argc - 1]); //last line where the latest username is
	if (*retr == returnedValue) *retr = "true";
	else *retr = "false"; //if the passwords match, return "true" and "False" otherwise
	return 0;
}
DataBase& DataBase::operator=(DataBase arg)
{
	this->db = arg.db; //having the same sqlite
}