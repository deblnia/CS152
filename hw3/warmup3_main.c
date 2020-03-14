#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup3.h" 

int main()
{
	 // Checking print_board
        char board[8][8];
        print_board(board);

        // Checking removes max
        int array[]={0,3,8,26,26,16,17};
        remove_max(array, 7);
	int one_array[] = {25,12,1,2}; 
	remove_max(one_array, 4); 
	int two_array[] = {12,4,3,7,20} 
	remove_max(two_array, 5); 

        //Checking init_board
        init_board(board);

        //Checking place_piece
        char player = 'K';
        unsigned int row = 3;
        unsigned int col = 5;
        place_piece(board, player, row, col);

        //Checking area_and_perimeter
        double height = 5.00;
        double length = 2.00;
        double area = 0.00;
        double perimeter = 0.00;
        area_and_perimeter(height, length, &area, &perimeter);
       	printf("Height %lf, Length %lf, Area %lf, Perimeter %lf\n",
                height, length, area, perimeter);

        //Checking remove_max_in_out
        int other_array[]={1,4,5,3,25,6,25};
        unsigned int other_length = 7;
        remove_max_in_out(other_array, &other_length);
} 
	
