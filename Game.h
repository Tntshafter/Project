#include <iostream>
#include <string>
#include "Question.h"
#include "DataBase.h"
#include <map>
using namespace std;
class Game
{
public:
	Game(const vector<User*>&, int, DataBase&);
	~Game();
	void sendFirstQuestion();
	void handleFinishGame();
	bool handleNextTurn();
	bool handleAnswerFromUser(User*, int, int);
	bool leaveGame(User *);
	int getID();
private:
	int _gameId; //added for obvious reasons
	vector<Question*> _questions;
	vector<User *> _players;
	int _questions_no;
	int _currQuestionIndex;
	DataBase &_db;
	map<std::string, int> _results;
	int _currentTurnAnswers;
	bool insertGameToDB();
	void initQuestionsFromDB();
	void sendQuestionToAllUsers();
};