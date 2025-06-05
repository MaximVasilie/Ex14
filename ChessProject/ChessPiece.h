#pragma once
#include <string>
#include <vector>


class ChessPiece 
{
protected:
    bool white;

public:
    ChessPiece(bool isWhite) : white(isWhite) {}
    virtual ~ChessPiece() {}
    bool isWhite() const { return white; }
    virtual char getSymbol() const = 0;
    virtual bool isValidMove(int srcRow, int srcCol, int dstRow, int dstCol,
        const std::vector<std::vector<ChessPiece*>>& board) const = 0;
};

