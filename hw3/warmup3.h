#ifndef WARMUP3_H
#define WARMUP3_H
#define NUM_ROWS 8 
#define NUM_COLS 8 



/*void print_board
* here's the docstring
*/ 
void print_board(char board[NUM_ROWS][NUM_COLS]); 

/*remove_max
 *
 */ 
int remove_max(int array[], unsigned int length);  


/*void_init_board
 *
 */ 
void init_board(char board[NUM_ROWS][NUM_COLS]); 

/*place_piece
 *
 */ 
unsigned int place_piece(char board[NUM_ROWS][NUM_COLS], char player, 
				unsigned int row, unsigned int col);


/*area_and_perimeter
 *
 */ 
void area_and_perimeter(double height, double length, double *area, 
				double *perimeter); 


/*remove_max_in_out
 *
 */ 
int remove_max_in_out(int array[], unsigned int *length); 



#endif 
