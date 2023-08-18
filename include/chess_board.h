#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "defs.h"

#define BOARD_WIDTH             34
#define BOARD_HEIGHT            21

#define CHESS_TYPE_KING         0
#define CHESS_TYPE_ADVISOR      1
#define CHESS_TYPE_ELEPHANT     2
#define CHESS_TYPE_ROOK         3
#define CHESS_TYPE_KNIGHT       4
#define CHESS_TYPE_CANNON       5
#define CHESS_TYPE_PAWN         6

#define HEADING_DIRECTION_UP    0
#define HEADING_DIRECTION_DOWN  1

#define RED_SIDE                0
#define BLACK_SIDE              1

#define RIVER_CROSSED           1
#define RIVER_NOT_CROSSED       0

#define ALIVE                   1
#define DEAD                    0

typedef struct _ChessPiece{
    int chess_type;
    int red_or_black;
    int cross_river;
    int cur_x_coordinate, cur_y_coordinate;
    int last_x_coordinate, last_y_coordinate;
    int heading_direction;
    int is_alive;
    CChar *name;

}ChessPiece;

extern CChar * default_chess_board[BOARD_HEIGHT][BOARD_WIDTH];

void Line_Init(CChar * board[][BOARD_WIDTH], char *str, int line_index);
void Init_Default_Chess_Board();
void Print_Line(CChar * board[][BOARD_WIDTH], int line_index);

void Print_Board(CChar * board[][BOARD_WIDTH]);

void Init_Chess_PieceN(int chess_piece_index, int pos_x, int pos_y, char *name, int color, int type);
void Init_Chess_Pieces();

void Paint_Chess_Piece(ChessPiece chess_piece);
void Paint_Board();

#endif  //  CHESS_BOARD_H 