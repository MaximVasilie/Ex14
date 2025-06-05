#pragma once
#include "ChessPiece.h"

#define WHITE_QUEEN 'Q'
#define BLACK_QUEEN 'q'

class Queen : public ChessPiece
{
public:
    Queen(bool isWhite) : ChessPiece(isWhite) {}
    char getSymbol() const override { return white ? WHITE_QUEEN : BLACK_QUEEN; }
    bool isValidMove(int srcRow, int srcCol, int dstRow, int dstCol,
        const std::vector<std::vector<ChessPiece*>>& board) const override;
   
};

