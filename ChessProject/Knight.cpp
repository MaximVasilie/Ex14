#include "Knight.h"

bool Knight::isValidMove(int srcRow, int srcCol, int dstRow, int dstCol,
    const std::vector<std::vector<ChessPiece*>>& board) const 
{
    int dRow = abs(srcRow - dstRow);
    int dCol = abs(srcCol - dstCol);
    return (dRow == NUM_CELL_MOVE_ROW_KNIGHT_ONE && dCol == NUM_CELL_MOVE_COLUMN_KNIGHT_ONE) || (dRow == NUM_CELL_MOVE_ROW_KNIGHT_TWO && dCol == NUM_CELL_MOVE_COLUMN_KNIGHT_TWO);
}

