#include "Game.h"
#include "User.h"
#include "Protocol.h"
Game::Game(const vector<User*>& users, int num, DataBase& db) : _db(db) //providing "official" initializer for the db to prevent errors
{
	_players = users;
	 _questions_no = num;
	 _currQuestionIndex = 0;
	_currentTurnAnswers = 0;
	_questions = db.initQuestions(num);
	
}
Game::~Game()
{
	for (int i = 0; i < _questions.size(); i++)
	{
		delete(_questions[i]);
	}
}
void Game::sendFirstQuestion()
{
	//now seriously, WHAT IS THIS? this is the most useless function i have yet to see -,-
	sendQuestionToAllUsers();
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
bool Game::leaveGame(User * use)
{
	if (_currQuestionIndex + 1 == _questions_no)
	{
		return false; //game already over
	}

}
int Game::getID()
{
	
}
bool Game::insertGameToDB()
{

}
void Game::initQuestionsFromDB()
{
	_questions = _db.initQuestions(_questions_no);
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