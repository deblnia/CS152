#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup3.h"

int main()
{
        // Checking print_board
        char board[8][8];
        print_board(board);

        //Checking init_board
        init_board(board);

        //Checking place_piece
        char player = 'K';
        unsigned int row = 3;
        unsigned int col = 5;
        place_piece(board, player, row, col);

	//Checking player_won 
	
	//Testing Checkers
	test_checkers(); 
}

