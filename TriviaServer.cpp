#include "TriviaServer.h"
#include "Protocol.h"
#include "Helper.h"
TriviaServer::TriviaServer()
{

}
TriviaServer::~TriviaServer()
{

}

void TriviaServer::serve()
{

}

void TriviaServer::bindAndListen()
{

}
void TriviaServer::accept()
{

}
void TriviaServer::clientHandler(SOCKET)
{

}
void TriviaServer::safeDeleteUser(RecievedMessage*)
{

}

User* TriviaServer::handleSignin(RecievedMessage* msg)
{
	Helper help;
	string user = "", pass = "";
	vector <string> list = msg->getValues();
	user = list[0];
	pass = list[1];
	bool flag = _db.isUserAndPassMatch(user,pass);
	if (flag)
	{
		for (int i = 0; i < this->_connectedUsers.size(); i++) //checking user is not already connected
		{
			if (_connectedUsers[i]->getUsername() == user)
			{
				flag = false;
			}
		}
		if (flag)
		{
			User * us = new User(user, msg->getSock());
			return us;
		}
		else
		{
			help.sendData(msg->getSock(), FAILED_SIGNIN_USER_CONNECTED);
			return nullptr;
		}
	}
	else
	{
		help.sendData(msg->getSock(), FAILED_SIGNIN_WRONG_DETAILS);
		return nullptr;
	}
}
bool TriviaServer::handleSignup(RecievedMessage*)
{

}
void TriviaServer::handleSignout(RecievedMessage* msg)
{
	for (int i = 0; i < this->_connectedUsers.size(); i++) 
	{
		if (msg->getSock() == _connectedUsers[i]->getSocket())
		{
			_connectedUsers.erase(std::remove(_connectedUsers.begin(), _connectedUsers.end(), _connectedUsers[i]), _connectedUsers.end());
			//erase-remove idiom, since using being() + int gives an error somewhy.
		}
	}
}

void TriviaServer::handleLeaveGame(RecievedMessage*)
{

}
void TriviaServer::handleStartGame(RecievedMessage*)
{

}
void TriviaServer::handlePlayerAnswer(RecievedMessage*)
{

}

bool TriviaServer::handleCreateRoom(RecievedMessage*)
{

}
bool TriviaServer::handleCloseRoom(RecievedMessage*)
{

}
bool TriviaServer::handleJoinRoom(RecievedMessage*)
{

}
bool TriviaServer::handleLeaveRoom(RecievedMessage*)
{

}
void TriviaServer::handleGetUsersInRoom(RecievedMessage*)
{

}
void TriviaServer::handleGetRooms(RecievedMessage*)
{

}

void TriviaServer::handleGetBestScores(RecievedMessage*)
{

}
void TriviaServer::handleGetPersonalStatus(RecievedMessage*)
{

}

void TriviaServer::handleRecievedMessages()
{

}
void TriviaServer::addRecievedMessage(RecievedMessage*)
{

}
RecievedMessage* TriviaServer::buildRecieveMessage(SOCKET, int)
{

}

User* TriviaServer::getUserByName(string)
{

}
User* TriviaServer::getUserBySocket(SOCKET)
{

}
Room* TriviaServer::getRoomById(int)
{

}

