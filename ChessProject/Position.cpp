#include "Position.h"

// Thus function is a c'tor
Position::Position(const int arrIndex, const std::string boardIndex)
{
	if (!(isValidPosition(arrIndex, boardIndex)))
	{
		std::cout << "Error(code 5): Piece an't be with index " << arrIndex << " || " << boardIndex << ".";
		exit(1);
	}
}

// This function is the d'tor(does nothing).
Position::~Position()
{
}

/*
This function will check if the givven indexes are valid for our chess board.
Input: arrIndex - should be 0 to 63, boardIndex - should be in the validBoardIndexes arr.
Output: true if the indexes are valid, otherwise false.
*/
bool Position::isValidPosition(const int arrIndex, const std::string boardIndex)
{
	if (arrIndex >= MIN_ARR_INDEX && arrIndex <= MAX_ARR_INDEX) // check if valid index for arr
	{
		for (int i = 0; i <= MAX_ARR_INDEX; i++)
		{
			if (boardIndex == validBoardIndexes[i]) // check if the board index is in the arr of valid indexes
			{
				return true;
			}
		}
	}

	return false;
}

/*
This function will set a new arrIndex and boardIndex.
Input: newArrIndex - number that should be between 0 to 63, newBoardIndex - a string that should be in the validBoardIndexes arr.
Output: none.
*/
void Position::setNewIndex(const int newArrIndex, const std::string newBoardIndex)
{
	this->_arrIndex = newArrIndex;
	this->_boardIndex = newBoardIndex;
}
