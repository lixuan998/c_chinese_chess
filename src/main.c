#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "chess_board.h"

int main()
{
    Init_Default_Chess_Board();
    //Print_Board(default_chess_board);
    Init_Chess_Pieces();
    Paint_Board();
}