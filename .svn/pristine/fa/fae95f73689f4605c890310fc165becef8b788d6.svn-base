#ifndef CHECKERS_H 
#define CHECKERS_H
#define NUM_ROWS 8 
#define NUM_COLS 8 

/*void print_board
* here's the docstring
*/
void print_board(char board[NUM_ROWS][NUM_COLS]);


/*void_init_board
 *
 */
void init_board(char board[NUM_ROWS][NUM_COLS]);

/*place_piece
 *
 */
unsigned int place_piece(char board[NUM_ROWS][NUM_COLS], char player,
                                unsigned int row, unsigned int col);

/*play_checkers
 * docstring
 */ 
void play_checkers(); 

/* player_won
 * a function that chekcs if a person has won after a play
 * inputs:
 *      char board[NUM_ROWS][NUM_COLS]
 * outputs:
 *      returns 0 if the player has not won and 1 if they have */

int player_won(char board[NUM_ROWS][NUM_COLS], char player);


/* do_move
 * performs all checks to make sure it is a valid move
 * inputs:
 *      char player - player character
 *      uint startrow - starting row
 *      uint startcol - starting column
 *      uint endrow - ending row
 *      uint endcol - ending column
 *      char board[8][8] - 8x8 board
 * outputs:
 *      returns 0 if invalid move,
 *      returns 1 if it is a valid move that moves 1 token
 *      returns 2 if it was a valid move that had one token
 *              jump another (capturing piece)
 */
unsigned int do_move(char player, unsigned int startrow, unsigned int startcol, unsigned int endrow, unsigned int endcol, char board[8][8]); 


/* test_checkers
 * testing individual functions
 */
void test_checkers(); 



/* computer_move
 * inputs:
 *      char board[NUM_ROWS][NUM_COLS]
 *      char player
 *      uint *row
 *      uint *col
 * outputs:
 *      return 1 if made a move
 *      0 if not
 */
int computer_move(char board[NUM_ROWS][NUM_COLS], char player,
        unsigned int *row, unsigned int *col);  
#endif  
