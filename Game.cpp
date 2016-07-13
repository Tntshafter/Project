#include "Game.h"
#include "User.h"
#include "Protocol.h"
#include <map>
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
	_db.updateGameStatus(_gameId);

	string message = FINISHED_GAME_CODE + to_string(_players.size());
	for (int i = 0; i < _players.size();i++) // collecting the message
	{
		message += SPACE + _players[i]->getUsername() + "  " + to_string(_results[_players[i]->getUsername()]); //as intended in the message
	}
	for (int i = 0; i < _players.size(); i++)//sending it out
	{
		_players[i]->send(message);
		_players[i]->setGame(nullptr);
	}
}
bool Game::handleNextTurn()
{
	if (_currQuestionIndex == _questions_no - 1) return false; //if the game is over
	if (_players.size() < 2) handleFinishGame(); //if there are not enough players
	if (_currAnswersAmount < _players.size()) return true;
	else
	{
		if (_currQuestionIndex == _questions_no - 2) //if its the last round
		{

		}
		else
		{
			_currQuestionIndex++;
			sendQuestionToAllUsers();
			_currAnswersAmount = 0;//setting it to 0 to recount it
		}
	}
	return true;
}
bool Game::handleAnswerFromUser(User* user, int index, int time)
{
	_currAnswersAmount++;
	bool corrAnswer = false;
	if (index == _questions[_currQuestionIndex]->getCorrectAnswerIndex() && time <=60)
	{
		corrAnswer = true;
		_results[user->getUsername()]++;
	}
	int sendValue;
	if (corrAnswer)
	{
		sendValue = 1;
	}
	else sendValue = 0;
	user->send(CORRECT_ANSWER + to_string(sendValue)); //sending back thhe correctness of the answer
	string answer = _questions[_currQuestionIndex]->getAnswers()[index];
	if (time > 60)
	{
		answer = "";
	}
	//now i do not know how "5" could mean *not in time* since im trying to use seconds here. instead, if its higher than 60 ill do so.
	_db.addAnswerToPlayer(_gameId, user->getUsername(), _questions[_currQuestionIndex]->getId(),
		answer, corrAnswer, time);
	_currentTurnAnswers++;
}
bool Game::leaveGame(User * use)
{
	if (_currQuestionIndex + 1 == _questions_no)
	{
		return false; //game already over
	}
	use->setGame(nullptr);
	bool res=handleNextTurn();
	if (!res)
	{
		handleFinishGame();
	}
}
int Game::getID()
{
	return _gameId;
}
bool Game::insertGameToDB()
{
	_gameId = _db.InsertNewGame();
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