#pragma once
#include "ChessPiece.h"

#define WHITE_BISHOP 'B'
#define BLACK_BISHOP 'b'

class Bishop : public ChessPiece
{
public:
    Bishop(bool isWhite) : ChessPiece(isWhite) {}
    char getSymbol() const override { return white ? WHITE_BISHOP : BLACK_BISHOP; }
    bool isValidMove(int srcRow, int srcCol, int dstRow, int dstCol,
        const std::vector<std::vector<ChessPiece*>>& board) const override;

};