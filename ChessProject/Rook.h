#pragma once
#include "ChessPiece.h"


#define WHITE_QUEEN 'R'
#define BLACK_QUEEN 'r'

class Rook : public ChessPiece
{
private:
    bool isHorizontalMove(int srcRow, int dstRow) const;
    bool isVerticalMove(int srcCol, int dstCol) const;
public:
    Rook(bool isWhite) : ChessPiece(isWhite) {}
    bool isStraightLineMove(int srcRow, int srcCol, int dstRow, int dstCol) const;
    bool isRowClear(int srcRow, int srcCol, int dstCol,
        const std::vector<std::vector<ChessPiece*>>& board) const;
    bool isColumnClear(int srcRow, int dstRow, int srcCol,
        const std::vector<std::vector<ChessPiece*>>& board) const;
    char getSymbol() const override { return white ? WHITE_QUEEN : BLACK_QUEEN; }
    bool isValidMove(int srcRow, int srcCol, int dstRow, int dstCol,
        const std::vector<std::vector<ChessPiece*>>& board) const override;
    
};
