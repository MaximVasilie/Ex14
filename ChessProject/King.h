#pragma once
#include "ChessPiece.h"

#define WHITE_KING 'K'
#define BLACK_KING 'k'

#define NUM_CELL_MOVE_ROW_KING 1
#define NUM_CELL_MOVE_COLUMN_KING 1

class King : public ChessPiece
{
public:
    King(bool isWhite) : ChessPiece(isWhite) {}
    char getSymbol() const override { return white ? WHITE_KING : BLACK_KING; }
    bool isValidMove(int srcRow, int srcCol, int dstRow, int dstCol,
        const std::vector<std::vector<ChessPiece*>>& board) const override;
    
};
