#include "DataBase.h"
#include "sqlite3.h"
#include "Protocol.h"
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
	string command =USER_EXISTS_COMMAND+username+FINISH_SQL_COMMAND;
	char ** err;
	bool *exists;
	int rc = sqlite3_exec(db,command.c_str(),callbackExists,exists,err);
	return *exists;
}
bool DataBase::addNewUser(string username, string password, string email)
{
	string command = INSERT_NEW_USER_COMMAND+username+","+password+","+email+FINISH_SQL_COMMAND_2;
	char ** err;
	int rc = sqlite3_exec(db, command.c_str(), nullptr, nullptr, err);
	if (rc != SQLITE_OK) return false; //unsuccessfull operation for reasons.
	else return true;
}
bool DataBase::isUserAndPassMatch(string username , string password)
{
	string command = CHECK_LOGIN_COMMAND + username + FINISH_SQL_COMMAND;
	char ** err;
	string * pass = new string(password);
	int rc = sqlite3_exec(db, command.c_str(), callbackLoginCheck, pass, err);
	if (rc != SQLITE_OK) return false; //unsuccessfull operation for reasons.
	if (pass->compare("true") == 0) return true; //callback returned true
	else return false;
}
vector<Question*> DataBase::initQuestions(int number)
{
	//collect ALL question - and THEN remove the un-needed amount

}
vector<string> DataBase::getBestScores()
{

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
bool DataBase::updateGameStatus(int)
{

}
bool DataBase::addAnswerToPlayer(int, string, int, string, bool, int)
{

}
int DataBase::callbackCount(void*, int argc, char**argv, char**azColName)
{

}
int DataBase::callbackQuestions(void*, int argc, char**argv, char**azColName)
{

}
int DataBase::callbackBestScores(void*, int argc, char**argv, char**azColName)
{

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