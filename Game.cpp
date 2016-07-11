#include "Game.h"
#include "User.h"
Game::Game(const vector<User*>& users, int num, DataBase& db)
{
	_players = users;
	 _questions_no = num;
	 _currQuestionIndex = 0;
	this->_db = db;
	_currentTurnAnswers = 0;
	// make = operator copy and make new questions here
	//_questions = db.initQuestions(num);
}
Game::~Game()
{

}
void Game::sendFirstQuestion()
{

}
void Game::handleFinishGame()
{

}
bool Game::handleNextTurn()
{

}
bool Game::handleAnswerFromUser(User*, int, int)
{

}
bool Game::leaveGame(User *)
{
	//check if user is admin ..?
}
int Game::getID()
{

}
bool Game::insertGameToDB()
{

}
void Game::initQuestionsFromDB()
{

}
void Game::sendQuestionToAllUsers()
{

}