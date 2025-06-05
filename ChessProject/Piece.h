#pragma once

#include <unordered_map>
#include "Position.h"
#include "Board.h"

class Board;

enum whitePieces {
	wKing = 'K', wQueen = 'Q', wRook = 'R', wKnight = 'N', wBishop = 'B', wPawn = 'P'
};

enum blackPieces {
	bKing = 'k', bQueen = 'q', bRook = 'r', bKnight = 'n', bBishop = 'b', bPawn = 'p'
};

class Piece
{
private:
	// fields
	char _type; // will contain the Piece type(for example k for king) and the color((small)k - black, (big)K - white)
	Position _position; // will contain a number index(for the arr of the chess board) and the index on the chess board(like a2) example - "09b7"(09 for index in arr, b7 for index on the chess board)

	// methods
	bool isWhite(char type) const;
	bool isBlack(char type) const;

public:
	// constructors
	Piece(const char type, const Position position);
	virtual ~Piece();

	// methods
	//virtual int move(const std::string newIndex) = 0; // will return number between 0-8 that will represent the code of the move
	virtual std::unordered_map<int, Position> calcMoves(const Board& board) const = 0; // will return hushmap(key=index in the vector, value=for example->"e4")
	virtual int checkMove(const Position currPosition, const Position newPosition) const = 0; // will return the code of the move

	// getters
	char getType() const { return this->_type; };
	Position getIndex() const { return this->_position; };

	// setters
	bool setPosition(const Position position);
};
