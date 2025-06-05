#pragma once

#include "Piece.h"
#include <vector>
#include <memory>

class Piece;

class Board
{
private:
	std::vector<std::unique_ptr<Piece>> _board;
	char _currentColor; // '0' for white, otherwise black

public:
	// constructors
	Board(const std::string startingPosition);
	~Board();

	// methods
	int move(const char type, const std::string index); // will return number between 0-8 that will represent the code of the move

	// getters
	const std::vector<std::unique_ptr<Piece>>& getBoard() const { return this->_board; };
	char getCurrColor() const { return this->_currentColor; };
};
