#pragma once
#include "ChessPiece.h"

#define WHITE_PAWN 'P'
#define BLACK_PAWN 'p'


#define DIRECTION_WHITE_PAWN -1
#define DIRECTION_BLACK_PAWN 1

#define NUM_CCELLS_MOVE_START 2

#define ALLOWED_JUMP_CELL_WHITE 6
#define ALLOWED_JUMP_CELL_BLACK 1

#define IS_MOVE true
#define IS_NOT_MOVE false

class Pawn : public ChessPiece
{
private:
    int getDirection() const;
    bool isSameColumn(int srcCol, int dstCol) const;
    bool isPathClearForDoubleStep(int srcRow, int srcCol, int dstRow,
        const std::vector<std::vector<ChessPiece*>>& board, int direction) const;
    bool isOnStartingRow(int srcRow) const;
    bool isTwoStepsForward(int srcRow, int dstRow, int direction) const;
public:
    Pawn(bool isWhite) : ChessPiece(isWhite) {}
    char getSymbol() const override { return white ? WHITE_PAWN : BLACK_PAWN; }
    bool isValidMove(int srcRow, int srcCol, int dstRow, int dstCol,
        const std::vector<std::vector<ChessPiece*>>& board) const override;
    bool isSingleStepMove(int srcRow, int srcCol, int dstRow, int dstCol,
        const std::vector<std::vector<ChessPiece*>>& board, int direction) const;
    bool isDoubleStepMove(int srcRow, int srcCol, int dstRow, int dstCol,
        const std::vector<std::vector<ChessPiece*>>& board, int direction) const;
    bool isCaptureMove(int srcRow, int srcCol, int dstRow, int dstCol,
        const std::vector<std::vector<ChessPiece*>>& board, int direction) const;

};