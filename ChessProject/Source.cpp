#include "Pipe.h"
#include "ChessBoard.h"
#include <iostream>
#include <string>
#include <thread>
#include <cstdlib>
#include <ctime>

#define TRY_AGAIN "0"
#define EXIT "1"
#define TIME_TRY_AGAIN 500
#define BUFFER_SIZE 1024
#define END_GIME_GOOD 0
#define USER_NOT_TRY_AGIN_CONNECT 0 
#define OK_TRY_AGIN true
#define NOT_TRY_AGIN false

#define QUIT "quit"
#define ERR_CONNECT "Cannot connect to graphics"
#define MSG_TRY_AGAIN_OR_EXIT "Do you want to try again or exit? (%s-try again, %s-exit): "
#define MSG_TRY_AGAIN "Trying to connect again..."
#define MSG_MOVE_GIVE "Move received: "

using std::cout;
using std::endl;
using std::string;

void attemptConnection(Pipe& p, bool& isConnected);
void sendInitialBoardState(Pipe& p, ChessBoard& board);
void processGameLoop(Pipe& p, ChessBoard& board);
void mainNotConnect();
bool checkTryAgin();
bool isConnect(Pipe& p);

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    Pipe p;
    ChessBoard board;
    bool isConnected = p.connect();

    attemptConnection(p, isConnected);

    // Initial setup
    sendInitialBoardState(p, board);

    // Start the game loop
    processGameLoop(p, board);

    p.close();
    return (END_GIME_GOOD);
}



/*
This function attempts to establish a connection with the server .
It repeatedly asks the user if they want to try again or exit until a connection is established or the user chooses to exit.
p: The pipe object used for the connection.
isConnected: A reference to the connection status flag. The function modifies it based on whether the connection was successful.
return: None
Time: until the user not out or until it is connectied
*/
void attemptConnection(Pipe& p, bool& isConnected)
{
    string userResponse;
    while (!isConnected)
    {
        mainNotConnect();
        if (checkTryAgin() == OK_TRY_AGIN)
        {
            isConnected = isConnect(p);
        }
        else
        {
            p.close();
            exit(USER_NOT_TRY_AGIN_CONNECT);  // Exit the program if the user chooses not to try again
        }
    }
}

/*
This function attempts to reconnect to the server (graphics) by calling the connect() method of the Pipe class.
p: The pipe object used for the connection.
bool: true if the connection was successful, false otherwise.
Time:O(1), assuming the connection method is constant time.
*/
bool isConnect(Pipe& p)
{
    bool connect = false;
    cout << MSG_TRY_AGAIN << endl;
    Sleep(TIME_TRY_AGAIN);
    connect = p.connect();

    return(connect);
}


/*
This function checks whether the user wants to try reconnecting or exit the program.
Param: None
Return: bool: OK_TRY_AGAIN if the user chose to try again, NOT_TRY_AGIN if the user chose to exit.
Time:  O(1)
*/
bool checkTryAgin()
{
    string userResponse;

    std::cin >> userResponse;
    if (userResponse == TRY_AGAIN)
    {
        return(OK_TRY_AGIN);
    }
    else
    {
        return(NOT_TRY_AGIN);
    }
}


/*
This function displays an error message and prompts the user to either try to reconnect or exit the program.
Param:None
Return: None
Time: O(1)
*/
void mainNotConnect()
{
    cout << ERR_CONNECT << endl;
    printf(MSG_TRY_AGAIN_OR_EXIT, TRY_AGAIN, EXIT);
}


/*
This function sends the initial board state to the graphics.
p: The pipe object used for communication.
board : The chess board object containing the initial state.
Return: None
Time: O(n), where n is the size of the board state (usually constant).
*/
void sendInitialBoardState(Pipe& p, ChessBoard& board)
{
    char msgToGraphics[BUFFER_SIZE];
    strcpy_s(msgToGraphics, board.getBoardState().c_str());
    p.sendMessageToGraphics(msgToGraphics);
}


/*
This function processes the game loop. It continuously reads moves from the graphics, processes them, and sends the results back until the quit signal is received.
p: The pipe object used for communication.
board: The chess board object that handles the moves.
Return:None
Time complexity: O(n), where n is the number of moves received and processed.
*/
void processGameLoop(Pipe& p, ChessBoard& board)
{
    char msgToGraphics[BUFFER_SIZE];
    string response = "0";
    string msgFromGraphics = p.getMessageFromGraphics();

    while (msgFromGraphics != QUIT)
    {
        cout << MSG_MOVE_GIVE << msgFromGraphics << endl;

        // Process the move and get the result
        response = board.processMove(msgFromGraphics);
        strcpy_s(msgToGraphics, response.c_str());

        // Send result back to graphics
        p.sendMessageToGraphics(msgToGraphics);

        // Get the next move
        msgFromGraphics = p.getMessageFromGraphics();
    }
}