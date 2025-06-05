#include "Bishop.h"

bool Bishop::isValidMove(int srcRow, int srcCol, int dstRow, int dstCol,
    const std::vector<std::vector<ChessPiece*>>& board) const 
{
    if (abs(srcRow - dstRow) != abs(srcCol - dstCol)) return false;

    // Check if the path is clear
    int rowStep = (dstRow - srcRow) > 0 ? 1 : -1;
    int colStep = (dstCol - srcCol) > 0 ? 1 : -1;
    int r = srcRow + rowStep, c = srcCol + colStep;

    while (r != dstRow && c != dstCol) {
        if (board[r][c] != nullptr) return false;
        r += rowStep;
        c += colStep;
    }
    return true;
}
