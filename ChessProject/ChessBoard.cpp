#include "ChessBoard.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"


/*
 This function initializes the chessboard.
 Param: None.
 Return: None.
 Time: O(1)
 */
ChessBoard::ChessBoard() : isWhiteTurn(true)
{
    board.resize(BOARD_SIZE, std::vector<ChessPiece*>(BOARD_SIZE, nullptr));

    putStartPawns();
    putStartRooks();
    putStartKnights();
    putStartBishops();
    putStartQueens();
    putStartKings();
}


/*
This function places a chess piece on the board at the specified position.
 row - The row index on the board.
 col - The column index on the board.
 piece - The chess piece to be placed.
 Return: None.
 Time: O(1)
   */
void ChessBoard::putPiece(int row, int col, ChessPiece* piece)
{
    board[row][col] = piece;
}


/*
This function initializes all pawns on the board in their starting positions.
Param: None.
Return: None.
Time: O(BOARD_SIZE)
*/
void ChessBoard::putStartPawns()
{
    int i = 0;
    for (i = 0; i < BOARD_SIZE; ++i)
    {
        putPiece(BLACK_PAWN_ROW, i, new Pawn(IS_BLACK));
        putPiece(WHITE_PAWN_ROW, i, new Pawn(IS_WHITE));
    }
}

/*
This function places the rooks in their starting positions for both players.
Param: None.
Return: None.
Time: O(1)
*/
void ChessBoard::putStartRooks()
{
    putPiece(BLACK_PIECES_ROW, INX_FEST_ROOK_BLACK, new Rook(IS_BLACK));
    putPiece(BLACK_PIECES_ROW, INX_SECOND_ROOK_BLACK, new Rook(IS_BLACK));

    putPiece(WHITE_PIECES_ROW, INX_FEST_ROOK_WHITE, new Rook(IS_WHITE));
    putPiece(WHITE_PIECES_ROW, INX_SECOND_ROOK_WHIT, new Rook(IS_WHITE));
}


/*
This function places the knights in their starting positions for both players.
Param: None.
Return: None.
Time: O(1)
*/
void ChessBoard::putStartKnights()
{
    putPiece(BLACK_PIECES_ROW, INX_FEST_KNIGHT_BLACK, new Knight(IS_BLACK));
    putPiece(BLACK_PIECES_ROW, INX_SECOND_KNIGHT_BLACK, new Knight(IS_BLACK));

    putPiece(WHITE_PIECES_ROW, INX_FEST_KNIGHT_WHITE, new Knight(IS_WHITE));
    putPiece(WHITE_PIECES_ROW, INX_SECOND_KNIGHT_WHITE, new Knight(IS_WHITE));
}


/*
This function places the bishops in their starting positions for both players.
Param: None.
Return: None.
Time: O(1)
*/
void ChessBoard::putStartBishops()
{
    putPiece(BLACK_PIECES_ROW, INX_FEST_BISHOP_BLACK, new Bishop(IS_BLACK));
    putPiece(BLACK_PIECES_ROW, INX_SECOND_BISHOP_BLACK, new Bishop(IS_BLACK));

    putPiece(WHITE_PIECES_ROW, INX_FEST_BISHOP_WHITE, new Bishop(IS_WHITE));
    putPiece(WHITE_PIECES_ROW, INX_SECOND_BISHOP_WHITE, new Bishop(IS_WHITE));
}


/*
This function places the queens in their starting positions for both players.
Param: None.
Return: None.
Time: O(1)
*/
void ChessBoard::putStartQueens()
{
    putPiece(BLACK_PIECES_ROW, INX_QUEEN_BLACK, new Queen(IS_BLACK));
    putPiece(WHITE_PIECES_ROW, INX_QUEEN_WHITE, new Queen(IS_WHITE));
}


/*
This function places the kings in their starting positions for both players.
Param: None.
Return: None.
Time: O(1)
*/
void ChessBoard::putStartKings()
{
    putPiece(BLACK_PIECES_ROW, INX_KING_BLACK, new King(IS_BLACK));
    putPiece(WHITE_PIECES_ROW, INX_KING_WHITE, new King(IS_WHITE));
}


/*
This destructor frees memory allocated for all chess pieces on the board.
Param: None.
Return: None.
Time: O(n^2) - Iterates through all cells of the board to delete pieces.
*/
ChessBoard::~ChessBoard()
{
    for (auto& row : board)
    {
        for (auto& piece : row)
        {
            delete piece;
        }
    }
}


/*
This function generates a string representation of the current board state, including turn information.
Param: None.
Return:A string where each cell is represented by a piece symbol or an empty cell marker.
       Includes an indication of whose turn it is (white or black).
Time: O(n^2) - Iterates through all cells of the board.
   */
std::string ChessBoard::getBoardState()
{
    std::string state;
    for (const auto& row : board)
    {
        for (const auto& piece : row)
        {
            if (piece)
            {
                state += piece->getSymbol();
            }
            else
            {
                state += EMPTY_CELL;
            }
        }
    }
    state += (isWhiteTurn ? WHITES_MOVE : BLACKS_MOVE);
    state += '\0';
    return (state);
}


/*
This function processes a chess move, validates it, and updates the board state.
move - A string representing the move
Return: A status string indicating the result of the move (e.g., success or error codes).
Time: O(n) for potential move-related checks.
*/
std::string ChessBoard::processMove(const std::string& move)
{
    int srcRow = 0;
    int srcCol = 0;
    int dstRow = 0;
    int dstCol = 0;
    ChessPiece* piece;

    if (!isValidFormat(move))
    {
        return ERR_CELL_INX; // Checking the stroke format
    }
    parseMove(move, srcRow, srcCol, dstRow, dstCol);

    if (!areIndicesValid(srcRow, srcCol, dstRow, dstCol))
    {
        return ERR_CELL_INX; // Checking indexes
    }

    if (isSameCell(srcRow, srcCol, dstRow, dstCol))
    {
        return ERR_NOT_MOVE;
    }
    piece = board[srcRow][srcCol];
    if (!isPieceValid(piece))
    {
        return ERR_PIECE_NOT_EXIST; // Checking the correctness of the shape
    }

    if (!isMoveValid(piece, srcRow, srcCol, dstRow, dstCol))
    {
        return ERR_MOVE_PIECE; // Checking the progress
    }

    if (isSameColorPiece(dstRow, dstCol, piece))
    {
        // Cheack if we are not eat our pies
        return ERR_MOVE_PIECE;
    }

    performMove(piece, srcRow, srcCol, dstRow, dstCol); // Make move

    return SUCCESSFUL_MOVE;
}

/*
This function checks if the move string has a valid format.
move - The move string to validate.
Return:true if the format is valid, false otherwise.
Time: O(1)
*/
bool ChessBoard::isValidFormat(const std::string& move)
{
    return move.size() == MAX_SIZE_MSG_MOVE &&
        isLetterInRange(move[INT_LETERPMSG_MOVE_ONE]) &&
        isDigitInRange(move[INT_LETERPMSG_MOVE_TWO]) &&
        isLetterInRange(move[INT_LETERPMSG_MOVE_THREE]) &&
        isDigitInRange(move[INT_LETERPMSG_MOVE_FOUR]);
}


/*
This function verifies if a given letter is within the valid column range.
letter - The column letter to check.
Return:true if the letter is within range, false otherwise.
Time: O(1)
*/
bool ChessBoard::isLetterInRange(char letter)
{
    return letter >= MIN_LETTER_NAME_CALL && letter <= MAX_LETTER_NAME_CALL;
}


/*
This function verifies if a given digit is within the valid row range.
digit - The row digit to check.
Return: true if the digit is within range, false otherwise.
Time: O(1)
*/
bool ChessBoard::isDigitInRange(char digit)
{
    return digit >= MIN_NUM_NAME_CALL && digit <= MAX_NUM_NAME_CALL;
}


/*
This function extracts source and destination positions from a move string.
move - The move string
srcRow, srcCol - Output variables for the source position.
dstRow, dstCol - Output variables for the destination position.
Return: None.
Time: O(1)
*/
void ChessBoard::parseMove(const std::string& move, int& srcRow, int& srcCol, int& dstRow, int& dstCol)
{
    srcCol = getColumnIndex(move[INT_LETERPMSG_MOVE_ONE]);
    srcRow = getRowIndex(move[INT_LETERPMSG_MOVE_TWO]);

    dstCol = getColumnIndex(move[INT_LETERPMSG_MOVE_THREE]);
    dstRow = getRowIndex(move[INT_LETERPMSG_MOVE_FOUR]);
}


/*
This function converts a column letter to a board index.
col - The column letter to convert.
Return:The zero-based column index.
Time: O(1)
*/
int ChessBoard::getColumnIndex(char col)
{
    return col - MIN_LETTER_NAME_CALL;
}


/*
This function converts a row number  to a board index.
row - The row character to convert.
Return: The zero-based row index.
Time: O(1)
*/
int ChessBoard::getRowIndex(char row)
{
    return 8 - (row - '0');
}


/*
This function checks if the source and destination indices are within the valid board range.
srcRow, srcCol - Source row and column indices.
dstRow, dstCol - Destination row and column indices.
Return: true if all indices are valid, false otherwise.
Time: O(1)
*/
bool ChessBoard::areIndicesValid(int srcRow, int srcCol, int dstRow, int dstCol)
{
    return srcRow >= MIN_BOARD_INDEX && srcRow < BOARD_SIZE&&
        srcCol >= MIN_BOARD_INDEX && srcCol < BOARD_SIZE&&
        dstRow >= MIN_BOARD_INDEX && dstRow < BOARD_SIZE&&
        dstCol >= MIN_BOARD_INDEX && dstCol < BOARD_SIZE;
}


/*
This function validates the piece by checking its presence and if its color matches the current turn.
piece - Pointer to the piece being validated.
Return: true if the piece exists and has the correct color, false otherwise.
Time: O(1)
*/
bool ChessBoard::isPieceValid(ChessPiece* piece)
{
    return isPiecePresent(piece) && isPieceColorValid(piece);
}


/*
This function checks if a piece exists at the given location.
piece - Pointer to the piece to check.
Return:true if the piece is not null, false otherwise.
Time: O(1)
*/
bool ChessBoard::isPiecePresent(ChessPiece* piece)
{
    return piece != nullptr;
}


/*
This function verifies if the piece's color matches the current player's turn.
piece - Pointer to the piece being checked.
Return:true if the piece's color matches the current turn, false otherwise.
Time: O(1)
*/
bool ChessBoard::isPieceColorValid(ChessPiece* piece)
{
    return piece->isWhite() == isWhiteTurn;
}


/*
This function checks if a move is valid for a given piece.
piece - Pointer to the piece being moved.
srcRow, srcCol - Source position.
dstRow, dstCol - Destination position.
Return:true if the move is valid for the piece, false otherwise.
Time: O(n) - Depends on the piece's logic for move validation.
*/
bool ChessBoard::isMoveValid(ChessPiece* piece, int srcRow, int srcCol, int dstRow, int dstCol)
{
    return piece->isValidMove(srcRow, srcCol, dstRow, dstCol, board);
}


/*
This function executes the move by updating the board state and toggling the turn.
piece - Pointer to the piece being moved.
srcRow, srcCol - Source position.
dstRow, dstCol - Destination position.
Return: None.
Time: O(1)
*/
void ChessBoard::performMove(ChessPiece* piece, int srcRow, int srcCol, int dstRow, int dstCol)
{
    delete board[dstRow][dstCol]; // Deleting the shape on the target cell (if any)
    board[dstRow][dstCol] = piece; // Moving the selected shape
    board[srcRow][srcCol] = nullptr; // Clearing the initial cell
    isWhiteTurn = !isWhiteTurn; // Switching gears
}


/*
This function checks if the source and destination are the same cell.
srcRow, srcCol - Source position.
dstRow, dstCol - Destination position.
Return:true if the source and destination are the same, false otherwise.
Time: O(1)
*/
bool ChessBoard::isSameCell(int srcRow, int srcCol, int dstRow, int dstCol)
{
    return srcRow == dstRow && srcCol == dstCol;
}


/*
This function checks if the destination cell contains a piece of the same color as the moving piece.
dstRow, dstCol - Destination position.
piece - Pointer to the moving piece.
Return: true if the destination contains a piece of the same color, false otherwise.
Time: O(1)
*/
bool ChessBoard::isSameColorPiece(int dstRow, int dstCol, ChessPiece* piece)
{
    ChessPiece* dstPiece = board[dstRow][dstCol];
    return dstPiece != nullptr && dstPiece->isWhite() == piece->isWhite();
}