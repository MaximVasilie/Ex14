#pragma once
#include <string>
#include <vector>
#include "ChessPiece.h"


#define BOARD_SIZE 8

#define IS_BLACK false
#define IS_WHITE true

#define WHITE_PAWN_ROW 6
#define WHITE_PIECES_ROW 7
#define BLACK_PAWN_ROW 1
#define BLACK_PIECES_ROW 0

#define INX_FEST_ROOK_WHITE 0
#define INX_FEST_KNIGHT_WHITE 1
#define INX_FEST_BISHOP_WHITE 2
#define INX_QUEEN_WHITE 3
#define INX_KING_WHITE 4

#define INX_KING_BLACK INX_KING_WHITE
#define INX_QUEEN_BLACK INX_QUEEN_WHITE
#define INX_FEST_BISHOP_BLACK INX_FEST_BISHOP_WHITE
#define INX_FEST_KNIGHT_BLACK INX_FEST_KNIGHT_WHITE
#define INX_FEST_ROOK_BLACK INX_FEST_ROOK_WHITE

#define INX_SECOND_ROOK_WHIT 7
#define INX_SECOND_KNIGHT_WHITE 6
#define INX_SECOND_BISHOP_WHITE 5

#define INX_SECOND_ROOK_BLACK INX_SECOND_ROOK_WHIT
#define INX_SECOND_KNIGHT_BLACK INX_SECOND_KNIGHT_WHITE
#define INX_SECOND_BISHOP_BLACK INX_SECOND_BISHOP_WHITE

#define EMPTY_CELL '#'

#define WHITES_MOVE '1'
#define BLACKS_MOVE '0'

#define MAX_SIZE_MSG_MOVE 4
#define MIN_LETTER_NAME_CALL 'a'
#define MAX_LETTER_NAME_CALL 'h'
#define MIN_NUM_NAME_CALL '1'
#define MAX_NUM_NAME_CALL '8'

#define INT_LETERPMSG_MOVE_ONE 0
#define INT_LETERPMSG_MOVE_TWO 1
#define INT_LETERPMSG_MOVE_THREE 2
#define INT_LETERPMSG_MOVE_FOUR 3

#define MIN_BOARD_INDEX 0


#define SUCCESSFUL_MOVE "0"
#define ERR_PIECE_NOT_EXIST "2"
#define ERR_CELL_INX "5"
#define ERR_MOVE_PIECE "6"
#define ERR_NOT_MOVE "7"

class ChessBoard
{
private:
    std::vector<std::vector<ChessPiece*>> board;
    bool isWhiteTurn;

    void putStartPawns();
    void putStartRooks();
    void putStartKnights();
    void putStartBishops();
    void putStartQueens();
    void putStartKings();
    void putPiece(int row, int col, ChessPiece* piece);

    bool isValidFormat(const std::string& move);
    bool isLetterInRange(char letter);
    bool isDigitInRange(char digit);

    void parseMove(const std::string& move, int& srcRow, int& srcCol, int& dstRow, int& dstCol);
    int getColumnIndex(char col);
    int getRowIndex(char row);

    bool areIndicesValid(int srcRow, int srcCol, int dstRow, int dstCol);
    bool isPieceValid(ChessPiece* piece);
    bool isPiecePresent(ChessPiece* piece);

    bool isMoveValid(ChessPiece* piece, int srcRow, int srcCol, int dstRow, int dstCol);

    void performMove(ChessPiece* piece, int srcRow, int srcCol, int dstRow, int dstCol);
    bool isSameColorPiece(int dstRow, int dstCol, ChessPiece* piece);
    bool isSameCell(int srcRow, int srcCol, int dstRow, int dstCol);

public:
    ChessBoard();
    ~ChessBoard();
    std::string getBoardState();
    std::string processMove(const std::string& move);
    bool isPieceColorValid(ChessPiece* piece);
};

