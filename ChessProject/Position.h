#pragma once
#include <string>
#include <iostream>

#define MIN_ARR_INDEX 0
#define MAX_ARR_INDEX 63

const std::string validBoardIndexes[] = {
    "a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8",
    "b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8",
    "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8",
    "d1", "d2", "d3", "d4", "d5", "d6", "d7", "d8",
    "e1", "e2", "e3", "e4", "e5", "e6", "e7", "e8",
    "f1", "f2", "f3", "f4", "f5", "f6", "f7", "f8",
    "g1", "g2", "g3", "g4", "g5", "g6", "g7", "g8",
    "h1", "h2", "h3", "h4", "h5", "h6", "h7", "h8"
};

class Position
{
private:
	int _arrIndex;
	std::string _boardIndex;

public:
	// constructors
	Position(const int arrIndex, const std::string boardIndex);
	~Position();

    // methods
    static bool isValidPosition(const int arrIndex, const std::string boardIndex);

    // getters
    int getArrIndex() const { return this->_arrIndex; };
    std::string getBoardIndex() const { return this->_boardIndex; };

	// setter
    void setNewIndex(const int newArrIndex, const std::string newBoardIndex);
};
