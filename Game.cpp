#include "Game.h"
#include "User.h"
#include "Protocol.h"
Game::Game(const vector<User*>& users, int num, DataBase& db)
{
	_players = users;
	 _questions_no = num;
	 _currQuestionIndex = 0;
	this->_db = *db;
	_currentTurnAnswers = 0;
	_questions = db.initQuestions(num);
	
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
bool Game::handleAnswerFromUser(User*, int index, int time)
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
	string message = "118###";
	message += _questions[_currQuestionIndex]->getQuestion();
	string * answers = _questions[_currQuestionIndex]->getAnswers();
	for (int i = 0; i < ANSWER_ARRAY_SIZE; i++)
	{
		message += "###";
		message += answers[i];

	}
	for (int i = 0; i < _players.size(); i++)
	{
		_players[i]->send(message);
		//not supposed to fail here (1180)
	}
}