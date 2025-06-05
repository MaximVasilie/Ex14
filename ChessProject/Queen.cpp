#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

bool Queen::isValidMove(int srcRow, int srcCol, int dstRow, int dstCol,
    const std::vector<std::vector<ChessPiece*>>& board) const 
{
    Rook rook(white);
    Bishop bishop(white);
    return rook.isValidMove(srcRow, srcCol, dstRow, dstCol, board) ||
        bishop.isValidMove(srcRow, srcCol, dstRow, dstCol, board);
}

