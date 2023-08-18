#include "chess_board.h"

static ChessPiece chess_pieces[33];

static int chess_piece_distribution[11][10];

static int cur_side;

CChar * default_chess_board[BOARD_HEIGHT][BOARD_WIDTH];
// char default_chess_board[100][100] = {
//     {"╔═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╗"},
//     {"║   │   │   │ \\ │ / │   │   │   ║"},
//     {"╟───┼───┼───┼───┼───┼───┼───┼───╢"},
//     {"║   │   │   │ / │ \\ │   │   │   ║"},
//     {"╟───┼───┼───┼───┼───┼───┼───┼───╢"},
//     {"║   │   │   │   │   │   │   │   ║"},
//     {"╟───┼───┼───┼───┼───┼───┼───┼───╢"},
//     {"║   │   │   │   │   │   │   │   ║"},
//     {"╟═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╢"},
//     {"║    楚  河          汉  界     ║"},
//     {"╟═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╢"},
//     {"║   │   │   │   │   │   │   │   ║"},
//     {"╟───┼───┼───┼───┼───┼───┼───┼───╢"},
//     {"║   │   │   │   │   │   │   │   ║"},
//     {"╟───┼──┼───┼───┼───┼───┼───┼───╢"},
//     {"║   │   │   │ \\ │ / │   │   │   ║"},
//     {"╟───┼───┼───┼───┼───┼───┼───┼───╢"},
//     {"║   │   │   │ / │ \\ │   │   │   ║"},
//     {"╚═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╝"},
// };

void Line_Init(CChar * board[][BOARD_WIDTH], char *str, int line_index)
{
    char *_tmp_ptr = str;
    char *_word;
    CChar *_tmp_cchar;
    int line_length = 0;
    while(*_tmp_ptr != '\0')
    {
        if(((*_tmp_ptr) & CODEX_1_MASK) == CODEX_1_RESULT)
        {
            _word = (char *)malloc(sizeof(char) * 2);
            memset(_word, 0, sizeof(char) * 2);
            memcpy(_word, _tmp_ptr, 1);
            _tmp_ptr += 1;
            _tmp_cchar = CCharConstructor(_word, WITHOUT_COPY);
            board[line_index][line_length ++] = _tmp_cchar;
        }
        else if(((*_tmp_ptr) & CODEX_2_MASK) == CODEX_2_RESULT)
        {
            _word = (char *)malloc(sizeof(char) * 3);
            memset(_word, 0, sizeof(char) * 3);
            memcpy(_word, _tmp_ptr, 2);
            _tmp_ptr += 2;
            _tmp_cchar = CCharConstructor(_word, WITHOUT_COPY);
            board[line_index][line_length ++] = _tmp_cchar;
        }
        else if(((*_tmp_ptr) & CODEX_3_MASK) == CODEX_3_RESULT)
        {
            _word = (char *)malloc(sizeof(char) * 4);
            memset(_word, 0, sizeof(char) * 4);
            memcpy(_word, _tmp_ptr, 3);
            _tmp_ptr += 3;
            _tmp_cchar = CCharConstructor(_word, WITHOUT_COPY);
            default_chess_board[line_index][line_length ++] = _tmp_cchar;
        }
        else if(((*_tmp_ptr) & CODEX_4_MASK) == CODEX_4_RESULT)
        {
            _word = (char *)malloc(sizeof(char) * 5);
            memset(_word, 0, sizeof(char) * 5);
            memcpy(_word, _tmp_ptr, 4);
            _tmp_ptr += 4;
            _tmp_cchar = CCharConstructor(_word, WITHOUT_COPY);
            board[line_index][line_length ++] = _tmp_cchar;
        }
        else
        {
            perror("cstring.c line 48 unrecognized format");
            return;
        }
    }
    _tmp_cchar = CCharConstructor("", WITHOUT_COPY);
    for(int i = line_length; i < BOARD_WIDTH; ++ i)
        board[line_index][i] = _tmp_cchar;
}
void Init_Default_Chess_Board()
{
    Line_Init(default_chess_board, " 1   2   3   4   5   6   7   8   9", 0);
    Line_Init(default_chess_board, " ╔═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╗", 1);
    Line_Init(default_chess_board, " ║   │   │   │ \\ │ / │   │   │   ║", 2);
    Line_Init(default_chess_board, " ╟───┼───┼───┼───┼───┼───┼───┼───╢", 3);
    Line_Init(default_chess_board, " ║   │   │   │ / │ \\ │   │   │   ║", 4);
    Line_Init(default_chess_board, " ╟───┼───┼───┼───┼───┼───┼───┼───╢", 5);
    Line_Init(default_chess_board, " ║   │   │   │   │   │   │   │   ║", 6);
    Line_Init(default_chess_board, " ╟───┼───┼───┼───┼───┼───┼───┼───╢", 7);
    Line_Init(default_chess_board, " ║   │   │   │   │   │   │   │   ║", 8);
    Line_Init(default_chess_board, " ╟═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╢", 9);
    Line_Init(default_chess_board, " ║     楚  河          汉  界    ║", 10);
    Line_Init(default_chess_board, " ╟═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╢", 11);
    Line_Init(default_chess_board, " ║   │   │   │   │   │   │   │   ║", 12);
    Line_Init(default_chess_board, " ╟───┼───┼───┼───┼───┼───┼───┼───╢", 13);
    Line_Init(default_chess_board, " ║   │   │   │   │   │   │   │   ║", 14);
    Line_Init(default_chess_board, " ╟───┼───┼───┼───┼───┼───┼───┼───╢", 15);
    Line_Init(default_chess_board, " ║   │   │   │ \\ │ / │   │   │   ║", 16);
    Line_Init(default_chess_board, " ╟───┼───┼───┼───┼───┼───┼───┼───╢", 17);
    Line_Init(default_chess_board, " ║   │   │   │ / │ \\ │   │   │   ║", 18);
    Line_Init(default_chess_board, " ╚═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╝", 19);
    Line_Init(default_chess_board, " 9   8   7   6   5   4   3   2   1", 20);
}


void Print_Line(CChar * board[][BOARD_WIDTH], int line_index)
{
    for(int i = 0; i < BOARD_WIDTH; ++ i)
    {
        printf("%s", board[line_index][i]->raw_data(board[line_index][i]));
    }
    printf("\n");
}

void Print_Board(CChar * board[][BOARD_WIDTH])
{
    for(int i = 0; i < BOARD_HEIGHT; ++ i)
        Print_Line(board, i);
}

void Init_Chess_PieceN(int chess_piece_index, int pos_x, int pos_y, char *name, int color, int type)
{
    chess_pieces[chess_piece_index].red_or_black = color;
    chess_pieces[chess_piece_index].chess_type = type;
    chess_pieces[chess_piece_index].cross_river = RIVER_NOT_CROSSED;
    chess_pieces[chess_piece_index].heading_direction = color;
    chess_pieces[chess_piece_index].is_alive = ALIVE;
    chess_pieces[chess_piece_index].name = CCharConstructor(name, WITHOUT_COPY);
    chess_pieces[chess_piece_index].cur_x_coordinate = pos_x;
    chess_pieces[chess_piece_index].cur_y_coordinate = pos_y;
    chess_piece_distribution[pos_x][pos_y] = chess_piece_index;
}

void Init_Chess_Pieces()
{
    for(int i = 0; i <= 11; ++ i)
    {
        for(int j = 0; j <= 10; ++ j)
            chess_piece_distribution[i][j] = 0;
    }
    int pos_x, pos_y;
    pos_x = 7;
    pos_y = 1;

    for(int i = 1; i <= 5; ++ i)
    {
        Init_Chess_PieceN(i, pos_x, pos_y, "兵", RED_SIDE, CHESS_TYPE_PAWN);
        pos_y += 2;
    }
    
    pos_x = 8;
    pos_y = 2;

    for(int i = 6; i <= 7; ++ i)
    {
        Init_Chess_PieceN(i, pos_x, pos_y, "炮", RED_SIDE, CHESS_TYPE_CANNON);
        pos_y += 6;
    }

    Init_Chess_PieceN(8, 10, 1, "車", RED_SIDE, CHESS_TYPE_ROOK);
    Init_Chess_PieceN(9, 10, 2, "馬", RED_SIDE, CHESS_TYPE_KNIGHT);
    Init_Chess_PieceN(10, 10, 3, "相", RED_SIDE, CHESS_TYPE_ELEPHANT);
    Init_Chess_PieceN(11, 10, 4, "仕", RED_SIDE, CHESS_TYPE_ADVISOR);
    Init_Chess_PieceN(12, 10, 5, "帅", RED_SIDE, CHESS_TYPE_KING);
    Init_Chess_PieceN(13, 10, 6, "仕", RED_SIDE, CHESS_TYPE_ADVISOR);
    Init_Chess_PieceN(14, 10, 7, "相", RED_SIDE, CHESS_TYPE_ELEPHANT);
    Init_Chess_PieceN(15, 10, 8, "馬", RED_SIDE, CHESS_TYPE_KNIGHT);
    Init_Chess_PieceN(16, 10, 9, "車", RED_SIDE, CHESS_TYPE_ROOK);

    pos_x = 4;
    pos_y = 1;
    
    for(int i = 17; i <= 21; ++ i)
    {
        Init_Chess_PieceN(i, pos_x, pos_y, "卒", BLACK_SIDE, CHESS_TYPE_PAWN);
        pos_y += 2;
    }
    
    pos_x = 3;
    pos_y = 2;

    for(int i = 22; i <= 23; ++ i)
    {
        Init_Chess_PieceN(i, pos_x, pos_y, "炮", BLACK_SIDE, CHESS_TYPE_CANNON);
        pos_y += 6;
    }
    
    Init_Chess_PieceN(24, 1, 1, "車", BLACK_SIDE, CHESS_TYPE_ROOK);
    Init_Chess_PieceN(25, 1, 2, "马", BLACK_SIDE, CHESS_TYPE_KNIGHT);
    Init_Chess_PieceN(26, 1, 3, "象", BLACK_SIDE, CHESS_TYPE_ELEPHANT);
    Init_Chess_PieceN(27, 1, 4, "仕", BLACK_SIDE, CHESS_TYPE_ADVISOR);
    Init_Chess_PieceN(28, 1, 5, "帅", BLACK_SIDE, CHESS_TYPE_KING);
    Init_Chess_PieceN(29, 1, 6, "仕", BLACK_SIDE, CHESS_TYPE_ADVISOR);
    Init_Chess_PieceN(30, 1, 7, "象", BLACK_SIDE, CHESS_TYPE_ELEPHANT);
    Init_Chess_PieceN(31, 1, 8, "马", BLACK_SIDE, CHESS_TYPE_KNIGHT);
    Init_Chess_PieceN(32, 1, 9, "車", BLACK_SIDE, CHESS_TYPE_ROOK);

    cur_side = RED_SIDE;
}

void Paint_Chess_Piece(ChessPiece chess_piece)
{
    if(chess_piece.red_or_black == RED_SIDE)
    {
        printf("\033[1;31m%s\033[0m", chess_piece.name->raw_data(chess_piece.name));
    }
    else
    {
        printf("\033[1;30m%s\033[0m", chess_piece.name->raw_data(chess_piece.name));
    }
}

void Paint_Board()
{
    for(int i = 0; i < BOARD_HEIGHT; ++ i)
    {
        for(int j = 0; j < BOARD_WIDTH; ++ j)
        {
            //printf("i : %d, j : %d\n", i, j);
            
            if(j % 4 == 0 && i % 2 == 1)
            {
                //printf("chess dis: %d\n", chess_piece_distribution[i + 1][j / 4 + 1]);
                if(chess_piece_distribution[i / 2 + 1][j / 4 + 1])
                {
                    Paint_Chess_Piece(chess_pieces[chess_piece_distribution[i / 2 + 1][j / 4 + 1]]);
                    j ++;
                    continue;
                }
                else
                {
                    printf("%s", default_chess_board[i][j]->raw_data(default_chess_board[i][j]));
                }
            }
            else
            {
                //printf("default\n");
                printf("%s", default_chess_board[i][j]->raw_data(default_chess_board[i][j]));
            }
        }
        printf("\n");
    }
}