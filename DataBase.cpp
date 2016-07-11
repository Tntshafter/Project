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

}
bool DataBase::addNewUser(string username, string passowrd, string email)
{

}
bool DataBase::isUserAndPassMatch(string username , string password)
{

}
vector<Question*> DataBase::initQuestions(int number)
{

}
vector<string> DataBase::getBestScores()
{

}
vector<string> DataBase::getPersonalStatus(string)
{

}
int DataBase::InsertNewGame()
{

}
bool DataBase::updateGameStatus(int)
{

}
bool DataBase::addAnswerToPlayer(int, string, int, string, bool, int)
{

}
int DataBase::callbackCount(void*, int, char**, char**)
{

}
int DataBase::callbackQuestions(void*, int, char**, char**)
{

}
int DataBase::callbackBestScores(void*, int, char**, char**)
{

}
int DataBase::callbackCountPersonalStatus(void*, int, char**, char**)
{

}