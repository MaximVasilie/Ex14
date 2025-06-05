#include "Piece.h"

/*
This function will check if the Piece is white.
Input: type - a char that will contain the type of the Piece.
Output: true is the Piece is white, otherwise false.
*/
bool Piece::isWhite(char type) const
{
    switch (type)
    {
    case wKing:
        return true;
    case wQueen:
        return true;
    case wRook:
        return true;
    case wKnight:
        return true;
    case wBishop:
        return true;
    case wPawn:
        return true;
    default:
        return false;
    }
}

/*
This function will check if the Piece is black.
Input: type - a char that will contain the type of the Piece.
Output: true is the Piece is black, otherwise false.
*/
bool Piece::isBlack(char type) const
{
    switch (type)
    {
    case bKing:
        return true;
    case bQueen:
        return true;
    case bRook:
        return true;
    case bKnight:
        return true;
    case bBishop:
        return true;
    case bPawn:
        return true;
    default:
        return false;
    }
}

// This function is the c'tor
Piece::Piece(const char type, const Position position) : _type(type), _position(position)
{
}

// This function is the d'tor(does nothing)
Piece::~Piece()
{
}

/*
This function will set a new position(index) for the Piece.
Input: position - an object that contains an int index and a string index(like e4).
Output: true if the position is valid and changed, otherwise false.
*/
bool Piece::setPosition(const Position position)
{
    int arrIndex = position.getArrIndex();
    std::string boardIndex = position.getBoardIndex();
    if (Position::isValidPosition(arrIndex, boardIndex)) // check if the position is valid(not specific)
    {
        this->_position = position;
        return true;
    }

    return false;
}


