#include "Rook.h"

/*
This function checks if the rook moves horizontally.
srcRow - the starting row, dstRow - the target row
Return: true if the move is horizontal, false otherwise
Time: O(1)
 */
bool Rook::isHorizontalMove(int srcRow, int dstRow) const
{
    return srcRow == dstRow;
}

/*
 This functionn checks if the rook moves vertically.
 srcCol - the starting column, dstCol - the target column
 Return: true if the move is vertical, false otherwise
 Time: O(1)
 */
bool Rook::isVerticalMove(int srcCol, int dstCol) const
{
    return srcCol == dstCol;
}

/*
 This function checks if the rook moves in a straight line (either horizontally or vertically).
srcRow - the starting row, srcCol - the starting column
dstRow - the target row, dstCol - the target column
Return: true if the move is in a straight line , false otherwise
Time: O(1)
*/
bool Rook::isStraightLineMove(int srcRow, int srcCol, int dstRow, int dstCol) const
{
    return isHorizontalMove(srcRow, dstRow) || isVerticalMove(srcCol, dstCol);
}

bool Rook::isRowClear(int srcRow, int srcCol, int dstCol,
    const std::vector<std::vector<ChessPiece*>>& board) const 
{
    int col = 0;
    int step = (dstCol > srcCol) ? 1 : -1;
    for (col = srcCol + step; col != dstCol; col += step) 
    {
        if (board[srcRow][col] != nullptr)
        {
            return false; 
        }
    }
    return true;
}

bool Rook::isColumnClear(int srcRow, int dstRow, int srcCol,
    const std::vector<std::vector<ChessPiece*>>& board) const
{
    int step = (dstRow > srcRow) ? 1 : -1;
    for (int row = srcRow + step; row != dstRow; row += step) 
    {
        if (board[row][srcCol] != nullptr) 
        {
            return false;
        }
    }
    return true;
}

bool Rook::isValidMove(int srcRow, int srcCol, int dstRow, int dstCol,
    const std::vector<std::vector<ChessPiece*>>& board) const
{

    if (!isStraightLineMove(srcRow, srcCol, dstRow, dstCol))
        return false;

    if (srcRow == dstRow)
    {
        return isRowClear(srcRow, srcCol, dstCol, board);
    }
    else if (srcCol == dstCol)
    {
        return isColumnClear(srcRow, dstRow, srcCol, board);
    }

    return false;
}

