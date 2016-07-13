#include "TriviaServer.h"
#include "Protocol.h"
#include "Helper.h"
#include "Validator.h"
typedef std::map<SOCKET,User * >::iterator typo; //to scan users
Helper help;
TriviaServer::TriviaServer()
{
	//database

	//socket
	WSADATA wsa;
	SOCKET s;

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		exit(1);
	}

	printf("Initialised.\n");


	if ((s = socket(AF_INET, SOCK_STREAM, 8820)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}

	printf("Socket created.\n");

	
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
void TriviaServer::safeDeleteUser(RecievedMessage*msg)
{
	handleSignout(msg);
	int res = closesocket(msg->getSock());
	if (res == SOCKET_ERROR)
	{
		cout << "An error occurred while disconnecting a client.\n";
	}
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
bool TriviaServer::handleSignup(RecievedMessage* msg)
{
	string username, pass, email;
	//part one:
	vector<string> vec = msg->getValues();
	username = vec[0];
	pass = vec[1];
	email = vec[2];
	//part two:
	if (!isPasswordValid(pass))
	{
		help.sendData(msg->getSock(), ILLEGAL_PASSWORD);
		return false;
	}
	if (!isUsernameValid(username))
	{
		help.sendData(msg->getSock(), ILLEGAL_USERNAME);
		return false;
	}
	//part three:
	if (_db.isUserExists(username))
	{
		help.sendData(msg->getSock(), USERNAME_EXISTS);
		return false;
	}
	//part four:
	if (!_db.addNewUser(username, pass, email))
	{
		help.sendData(msg->getSock(), UNKNOWN_SIGNUP_ERROR);
		return false;
	}
	//part five:
	help.sendData(msg->getSock(), SUCCESS_SIGNUP);
	return true;
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
void TriviaServer::handlePlayerAnswer(RecievedMessage* msg)
{
	User * user = getUserBySocket(msg->getSock());
	bool res = user->getGame()->handleAnswerFromUser(user, msg->getValues[0], msg->getValues[1]);
	if (res == false)
	{
		delete(user->getGame());
		user->setGame(nullptr);
	}
}

bool TriviaServer::handleCreateRoom(RecievedMessage* msg)
{
	User * user = getUserBySocket(msg->getSock());
	if (user == nullptr) return false;
	_roomIdsequence++;
	vector<string> values = msg->getValues();
	bool flag =user->createRoom(_roomIdsequence, values[0], stoi(values[1]), stoi(values[2]), stoi(values[3]));
	if (flag) _roomsList.insert(std::pair<int, Room *>(_roomIdsequence, user->getRoom()));
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

User* TriviaServer::getUserByName(string username)
{
	for (typo iterator = _connectedUsers.begin(); iterator != _connectedUsers.end(); iterator++) //casual scan through the map
	{
		if (iterator->second->getUsername().compare(username) == 0) return iterator->second;
	}
	return nullptr;
}
User* TriviaServer::getUserBySocket(SOCKET sock)
{
	return _connectedUsers[sock];
}
Room* TriviaServer::getRoomById(int id)
{
	return _roomsList[id];
}

