#include <stdlib.h>
#include <stdio.h>
#include "checkers.h"

/* print_board
 * prints the contents of the checkerboard.
 * The pieces are 'b', 'w', the kinged ones
 * are 'B'and 'W', and empty spaces are '*'
 * inputs:
 *    char board[NUM_ROWS][NUM_COLS] - an NUM_ROWSxNUM_COLS board
 * outputs:
 *    none. prints the results.
 */
void print_board(char board[NUM_ROWS][NUM_COLS] )
{
        unsigned int i, j;
        printf("   ");
        for(j=0;j<NUM_COLS;j++)
        {
                printf("%u ",j);
        }
        printf("\n");
        for(i=0;i<NUM_ROWS;i++)
        {
                printf("%u: ",i);
                for(j=0;j<NUM_COLS;j++)
                {
                        printf("%c ",board[i][j]);
                }
                printf("\n");
        }
}

/*void_init_board
 *initializes board 
 *inputs: 
 *   char board[NUM_ROWS][NUM_COLS] - a NUM_ROWSxNUM_COLS board 
 *outputs: 
 * 	none. 
 */
void init_board(char board[NUM_ROWS][NUM_COLS])
{ 
	int k = 1; 
	int m = 1; 
	//placing blue pieces 
	for (char x = 1; x <= (NUM_ROWS-2)/2; x++){ 
        	for (char y=1; y <= NUM_COLS; y++){
			if(k==1)
				printf("b "); 

 			else
                        	printf("* ");

                k *= -1;
        	}
        	if(NUM_COLS % 2 == 0)
        	{	
                	k*= -1;
        	}
        	printf("\n");
	}

		//placing two rows in middle
	for (char x=0; x < 2; x++){
        	for (char y=0; y < NUM_COLS; y++){
                        printf("* ");
		} 
		printf("\n"); 
		}
		//place white pieces
		for (char x=1; x <= (NUM_ROWS-2)/2; x++){
        		for (char y=1; y <= NUM_COLS; y++){
                		if(m == 1)
                        		printf("w ");
                		else
                        		printf("* ");

                	m *= -1;
        		}
        	if(NUM_COLS % 2 == 0)
        	{	
                	m*= -1;
        	}	
        	printf("\n");
		}	
}
 
/*place_piece 
 * places piece 
 * inputs: 
 * 	char board[NUM_ROWS][NUM_COLS] - NUM_ROWSxNUM_COLS
 * 	char player - the piece represented by a character 
 * 	uint row - the row where the piece wants to move 
 * 	uint col - the col where the piece wants to move 
 * outputs: 
 * 	returns 0 if piece is not moved, and 1 if it is moved
 */ 
unsigned int place_piece(char board[NUM_ROWS][NUM_COLS], char player, unsigned int row, unsigned int col)
{

	if(row <= NUM_ROWS && col <= NUM_COLS){
        	if(board[row][col] == "* "){
                	board[row][col] == player;
                	return 1;
        	}
	}	
	else
        	return 0;

}

/*play_checkers
 * plays checkers against a human opponent
 * inputs: 
 * 	none. 
 * outputs: 
 * 	none 
 */ 
void play_checkers()
{

	char board[8][8] = { {'*','*','*','*','*','*','*','*'},
                             {'*','*','*','*','*','*','*','*'},
                             {'*','*','*','*','*','*','*','*'},
                             {'*','*','*','*','*','*','*','*'},
                             {'*','*','*','*','*','*','*','*'},
                             {'*','*','*','*','*','*','*','*'},
                             {'*','*','*','*','*','*','*','*'},
                             {'*','*','*','*','*','*','*','*'}  };
        init_board(board);
	int winner = 0;
	char player_turn = 'b';
	while (winner == 0)
	{
		unsigned int sr, sc, er, ec;
		unsigned int response;
		
		// obtain the player's move
		do {
			printf("Player %c, in what row (0-7) is the piece you are moving located? ",player_turn);
			scanf("%u",&sr);
			if (sr >= NUM_ROWS)
				printf("That is not a valid row. Try again.\n");
		} while (sr >= NUM_ROWS);
		do {
			printf("Player %c, in what column (0-7) is the piece you are moving located? ",player_turn);
			scanf("%u",&sc);
			if (sc >= NUM_COLS)
				printf("That is not a valid column. Try again.\n");
		} while (sc >= NUM_COLS);
		do {
			printf("Player %c, to what row (0-7) do you want to move it? ",player_turn);
			scanf("%u",&er);
			if (er >= NUM_ROWS)
				printf("That is not a valid row. Try again.\n");
		} while (er >= NUM_ROWS);
		do {
			printf("Player %c, to what column (0-7) do you want to move it? ",player_turn);
			scanf("%u",&ec);
			if (ec >= NUM_COLS)
				printf("That is not a valid column. Try again.\n");
		} while (ec >= NUM_COLS);

		// attempt to do the move
		response = do_move(player_turn, sr, sc, er, ec, board);

                // invalid move
                if (response == 0)
                {
                        printf("That is not a valid move. Try again.\n");
                }       
                // valid move, switch to other player
                else if (response == 1)
                {
                        winner = player_won(board, player_turn);
                        if (winner == 0)
                        {
                                printf("Valid move. Next player's turn\n");
                                player_turn = (player_turn == 'b '?'w ':'b ');
                        }       
                        else
                                printf("Congratulations! Player %c won!\n",player_turn);
                }               
                // captured opponent's piece - gets another turn
                else // if (response == 2)
                {
                        winner = player_won(board, player_turn);
                        if (winner == 0)
                        {
				
				char again;
                                printf("You jumped your opponent!\n");
                                do { 
                                        printf("Would you like to move again?\n");
                                        printf("Enter y for yes or n for no: \n");
                                        scanf(" %c\n",&again);
                                        if (again == 'n')
                                        {                
                                                player_turn = (player_turn == 'b'?'w':'b');
                                        }       
                                        else if (again != 'y')
                                        {
                                                printf("Invalid response.\n");
                                        }       
                                } while (!((again == 'n') || (again == 'y')));
                        }       
                        else
                                printf("Congratulations! Player %c won!\n",player_turn);
                }   

	} // end of while no winner
}

/* player_won
 * a function that chekcs if a person has won after a play
 * inputs:
 *      char board[NUM_ROWS][NUM_COLS]
 * outputs:
 *      returns 0 if the player has not won and 1 if they have */
int player_won(char board[NUM_ROWS][NUM_COLS], char player)
{ 
 	int i = 0;
        int j = 0;
        //Checking for capturing all opponents pieces
        for(i = 0; i < NUM_ROWS; i++){
                for (j = 0; j < NUM_COLS; j++){
                        if(board[i][j] == "w " &&
                                player == "b ") {
                                        return  0;
                        }
                        else if(board[i][j] == "b " &&
                                player == "w "){
                                        return 0;
                        }
                        else
                                return 1;
                }
        }
	
return 1;	 
} 

/* valid_move
 * inputs:
 :*      char player - player
 *      uint startrow - starting row
 *      uint startcol - starting col
 *      uint endrow - ending row
 *      uint endcol - ending col
 *      char board[8][8] - 8x8 board
 * outputs:
 *      returns 0 if invalid
 *      returns 1 if valid
 */
int valid_move(char player, unsigned int startrow, \
        unsigned int startcol, unsigned int endrow, \
        unsigned int endcol, char board[8][8])
{
        //checking if valid spot on board
        if (startrow <= NUM_ROWS && startcol <= NUM_COLS
                && endrow <= NUM_ROWS && endcol <= NUM_COLS)
        {       //checking if move is right direction
                if((player == "w " && startrow < endrow) ||  (player ==  "b " && startrow > endrow))
                {       //checking if move is diagonal
                        if((startcol == endcol + 1) || \
                        (startcol == endcol -1))
                        {
                                printf("valid move: startcol - %d \n startrow - %d \n endcol - %d\n, endrow - %d\n", startcol, startrow, endcol, endrow);  
				return 1;

                        } //not moving diagonally
                        else
                                return 0;
                } //not moving in the right direction
                else
                        return 0;
        }//off the board
        else
                return 0;
}

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
unsigned int do_move(char player, unsigned int startrow, unsigned int startcol, unsigned int endrow, unsigned int endcol, char board[8][8])
{ 
	if (valid_move(player,startrow,
                startcol, endrow,
                endcol, board) == 1)
        {       //One Case
		if (board[endrow][endcol] == '*'){
			place_piece(board, \
				player,endrow, endcol); 
				return 1; 
		}  
                //Two Case 
 		else if (player == 'w' && board[endrow][endcol] == 'b')
		{	// white moving right 
			if (endcol > startcol && board[endrow + 1][endcol+1] == '*' && (endcol + 1 < NUM_COLS && endrow + 1 < NUM_ROWS))
			{
			
		
				board[endrow][endcol] = '*'; 
				place_piece(board, player, endrow + 1, endcol + 1); 
				return 2; 
			} 
			//white moving left 
			else if (endcol < startcol && board[endrow + 1][endcol-1] == '*' && (endcol - 1 >= 0 && endrow + 1 < NUM_ROWS))
			{ 
				board[endrow][endcol] = '*';
                                place_piece(board, player, endrow + 1, endcol - 1);
                                return 2;
			} 
		}
		else if (player == 'b' && board[endrow][endcol] == 'w')
                {       // blue moving right
                        if (endcol > startcol && board[endrow - 1][endcol+1] == '*' && (endcol + 1 < NUM_COLS && endrow - 1 >= 0))
                        {
                                board[endrow][endcol] = '*';
                                place_piece(board, player, endrow - 1, endcol + 1);
                                return 2;
                        }
                        //blue moving left
                        else if (endcol < startcol && board[endrow - 1][endcol-1] == '*' && (endcol - 1 >= 0 && endrow - 1 >= 0))
                        {
                                board[endrow][endcol] = '*';
                                place_piece(board, player, endrow + 1, endcol - 1);
                                return 2;
                        }
                }

                //King Maker
                if (endrow == 0 && player == "b ")
                {
                        player == "B ";
                }
                else if (endrow == NUM_ROWS - 1 && player ==\
                                "w ")
                {
                        player == "W";
                }

		}
	//not valid move 
	return 0; 
}
		 


/* test_checkers
 * testing individual functions
 */
void test_checkers(){
	char player = 'w'; 
	unsigned int startrow = 0; 
	unsigned startcol = 2; 
	unsigned int endrow = 1; 
	unsigned int endcol = 3;
	char board_input[8][8];
	printf("test\n"); 
	init_board(board_input); 
	printf("calling valid move\n"); 
	valid_move(player, startrow, startcol, endrow, endcol, board_input); 
	

} 

