#include <string>
#include <WinSock2.h>
#include <vector>
#include "RecievedMessage.h"
#include "Room.h"

class TryviaServer{
	Using namespace std;

public:
     TriviaServer();
     ~TriviaServer();

	 void server();

	 void bindAndListen();
	 void accept();
	 void clientHandler(SOCKET);
	 void safeDeleteUser(RecievedMessage*);

	 user* handleSignin(RecievedMessage*);
	 bool handleSignup(RecievedMessage*);
	 void handleSignout(RecievedMessage*);

	 void handleLeaveGame(RecievedMessage*);
	 void handleStartGame(RecievedMessage*);
	 void handlePlayerAnswer(RecievedMessage*);

	 bool handleCreateRoom(RecievedMessage*);
	 bool handleCloseRoom(RecievedMessage*);
	 bool handleJoinRoom(RecievedMessage*);
	 bool handleLeaveRoom(RecievedMessage*);
	 void handleGetUsersInRoom(RecievedMessage*);
	 void handleGetRooms(RecievedMessage*);

	 void handleGetBestScores(RecievedMessage*);
	 void handleGetPersonalStatus(RecievedMessage*);

	 void handleRecievedMessages();
	 void addRecievedMessage(RecievedMessage*);
	 RecievedMessage* buildRecieveMessage(SOCKET, int);
	 
	 User* getUserByName(string);
	 User* getUserBySocket(SOCKET);
	 Room* getRoomById(int);



private:
	SOCKET _socket;
	map<SOCKET, User*> _connectedUsers;
	DataBase _db;
	map<int, Room*> _roomsList;

	mutex _mtxRecievedMessages;
	queue<


};