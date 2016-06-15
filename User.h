#include "Room.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <WinSock2.h>
class User
{
public:
	User(std::string, SOCKET);
	void send(std::string);
	std::string getUsername();
	SOCKET getSocket();
	Room* getRoom();
	Game* getGame();
	void setGame(Game*);
	void clearRoom();
	bool createRoom(int, std::string, int, int, int);
	bool joinRoom(Room*);
	void leaveRoom();
	int closeRoom();
	bool leaveGame();
private:
	std::string _username;
	Room * _currRoom;
	Game * _currGame;
	SOCKET _sock;
};