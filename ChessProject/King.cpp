#include "King.h"



/*
This function checks if the King piece can move from its current position to the target position.
srcRow: The row of the piece's current position.
srcCol: The column of the piece's current position.
dstRow: The row of the target position.
dstCol: The column of the target position.
board: The chess board where the piece is located.
Return: Returns true if the King can move to the target position, false otherwise.
Time: O(1)
*/
bool King::isValidMove(int srcRow, int srcCol, int dstRow, int dstCol,
    const std::vector<std::vector<ChessPiece*>>& board) const 
{
    int dRow = abs(srcRow - dstRow);
    int dCol = abs(srcCol - dstCol);
    return (dRow <= NUM_CELL_MOVE_ROW_KING && dCol <= NUM_CELL_MOVE_COLUMN_KING);
}


