#pragma once
#include "ChessPiece.h"

#define WHITE_KNIGHT 'N'
#define BLACK_KNIGHT 'n'

#define NUM_CELL_MOVE_ROW_KNIGHT_ONE 2
#define NUM_CELL_MOVE_COLUMN_KNIGHT_ONE 1

#define NUM_CELL_MOVE_ROW_KNIGHT_TWO 1
#define NUM_CELL_MOVE_COLUMN_KNIGHT_TWO 2

class Knight : public ChessPiece 
{
public:
    Knight(bool isWhite) : ChessPiece(isWhite) {}
    char getSymbol() const override { return white ? WHITE_KNIGHT : BLACK_KNIGHT; }
    bool isValidMove(int srcRow, int srcCol, int dstRow, int dstCol,
        const std::vector<std::vector<ChessPiece*>>& board) const override;
   
};

