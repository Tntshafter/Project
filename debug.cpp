/*the main purpose of this file to is be able to
  fully compile and check the program for errors,
  there there was a need for the code below */
#include "Database.h"
#include "Validator.h"
#include "Game.h"
#include "Helper.h"
#include "Question.h"
#include "RecievedMessage.h"
#include "User.h"
#include "Room.h"
#include "TriviaServer.h"
#include <time.h>
int main()
{
	//introduction
	/*
	yes. its a total chaos around here. i am sorry. 
	*/
	TriviaServer server;
	server.serve(); //should trigger the server loop
	srand(time(NULL));
	system("pause");
	return 0;
}