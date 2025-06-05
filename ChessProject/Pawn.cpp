#include "Pawn.h"

/*
This function returns the direction of the pawn movement 
(DIRECTION_WHITE_PAWN for white, DIRECTION_BLACK_PAWN for black)
Param: None
Return: direction of the pawn movement 
Time: o(1)
*/
int Pawn::getDirection() const
{
    return white ? DIRECTION_WHITE_PAWN : DIRECTION_BLACK_PAWN;
}


/*
This function checks if the pawn's move is a single step forward.
The move is valid if the pawn stays in the same column and the destination cell is empty.
srcRow: Current row of the pawn
srcCol: Current column of the pawn
dstRow: Target row for the move
dstCol: Target column for the move
board: Current state of the chessboard
direction: Direction of pawn movement
Return: true if the move is a single step forward, false otherwise
Time: O(1)
*/
bool Pawn::isSingleStepMove(int srcRow, int srcCol, int dstRow, int dstCol,
    const std::vector<std::vector<ChessPiece*>>& board, int direction) const 
{
    return srcCol == dstCol && board[dstRow][dstCol] == nullptr &&
        dstRow == srcRow + direction;
}



/*
This function checks if the pawn's move is a double step forward.
 srcRow: Current row of the pawn
 srcCol: Current column of the pawn
 dstRow: Target row for the move
 dstCol: Target column for the move
 board: Current state of the chessboard
 direction: Direction of pawn movement
Return: true if the move is a double step forward, false otherwise
Time: O(1)
*/
bool Pawn::isDoubleStepMove(int srcRow, int srcCol, int dstRow, int dstCol,
    const std::vector<std::vector<ChessPiece*>>& board, int direction) const
{
    return isSameColumn(srcCol, dstCol) &&
        isPathClearForDoubleStep(srcRow, srcCol, dstRow, board, direction) &&
        isOnStartingRow(srcRow) &&
        isTwoStepsForward(srcRow, dstRow, direction);
}

/*
This function checks if the pawn remains in the same column during its move.
srcCol: Current column of the pawn
dstCol: Target column for the move
Return: true if the pawn stays in the same column, false otherwise
Time: O(1)
*/
bool Pawn::isSameColumn(int srcCol, int dstCol) const 
{
    return srcCol == dstCol;
}


/*
This function checks if the cells along the path for a double step move are clear.
Both the intermediate cell and the destination cell must be empty.
srcRow: Current row of the pawn
srcCol: Current column of the pawn
dstRow: Target row for the move
board: Current state of the chessboard
direction: Direction of pawn movement
Return: true if the path is clear, false otherwise
Time: O(1)
*/
bool Pawn::isPathClearForDoubleStep(int srcRow, int srcCol, int dstRow,
    const std::vector<std::vector<ChessPiece*>>& board, int direction) const 
{
    return board[srcRow + direction][srcCol] == nullptr && board[dstRow][srcCol] == nullptr;
}


/*
This function checks if the pawn is on its starting row.
White pawns start at row ALLOWED_JUMP_CELL_WHITE.
Black pawns start at row ALLOWED_JUMP_CELL_BLACK.
srcRow: Current row of the pawn
Return: true if the pawn is on its starting row, false otherwise
Time: O(1)
*/
bool Pawn::isOnStartingRow(int srcRow) const 
{
    return (white && srcRow == ALLOWED_JUMP_CELL_WHITE) || (!white && srcRow == ALLOWED_JUMP_CELL_BLACK);
}


/*
This function checks if the pawn's move is exactly two steps forward.
The move is valid only if the target row equals the source row plus two steps
in the movement direction.
srcRow: Current row of the pawn
dstRow: Target row for the move
direction: Direction of pawn movement
Return: true if the pawn moves two steps forward, false otherwise
Time: O(1)
*/
bool Pawn::isTwoStepsForward(int srcRow, int dstRow, int direction) const
{
    return dstRow == srcRow + NUM_CCELLS_MOVE_START * direction;
}


/*
This function checks if the pawn captures an opponent's piece diagonally.
srcRow: Current row of the pawn
srcCol: Current column of the pawn
dstRow: Target row for the move
dstCol: Target column for the move
board: Current state of the chessboard
direction: Direction of pawn movement
Return: true if the pawn captures a piece diagonally, false otherwise
Time: O(1)
*/
bool Pawn::isCaptureMove(int srcRow, int srcCol, int dstRow, int dstCol,
    const std::vector<std::vector<ChessPiece*>>& board, int direction) const 
{
    return abs(srcCol - dstCol) == 1 && dstRow == srcRow + direction &&
        board[dstRow][dstCol] != nullptr &&
        board[dstRow][dstCol]->isWhite() != white; 
}


/*
This function checks if the pawn's move is valid.
srcRow: Current row of the pawn
srcCol: Current column of the pawn
dstRow: Target row for the move
dstCol: Target column for the move
board: Current state of the chessboard
Return: IS_MOVE if the move is valid, IS_NOT_MOVE otherwise
Time: O(1)
*/
bool Pawn::isValidMove(int srcRow, int srcCol, int dstRow, int dstCol,
    const std::vector<std::vector<ChessPiece*>>& board) const
{
    int direction = getDirection();

    
    if (isSingleStepMove(srcRow, srcCol, dstRow, dstCol, board, direction))
    {
        //check the movement one square ahead
        return (IS_MOVE);
    }

    if (isDoubleStepMove(srcRow, srcCol, dstRow, dstCol, board, direction)) 
    {
        //check the movement two squares ahead
        return (IS_MOVE);
    }

    if (isCaptureMove(srcRow, srcCol, dstRow, dstCol, board, direction))
    {
        //check the capture of the figure diagonally
        return (IS_MOVE);
    }

    return (IS_NOT_MOVE);
}
