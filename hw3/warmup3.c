#include <stdlib.h>
#include <stdio.h>
#include "warmup3.h"

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
        for(i=0;i<NUM_ROWS;i++)
        {
                for(j=0;j<NUM_COLS;j++)
                {
                }
                printf("\n");
        }
}

/* remove_max
 *removes removes all instances of max from array and returns max  
 */ 
int remove_max(int array[], unsigned int length) 
{ 
 
int max = 0;  
//finding the max 
for (int x=0; x<length; x++){ 
	if(array[x] > max){
		max = array[x]; 
	}

}
//replacing all instances of the max 
for (int i=0; i<length; i++){
	if (array[i] == max){
		for(int j = i; j < length -1;j++)
		{
			array[j] = array[j+1];  
		}
	i--;   
	}
}
return max;  
} 

/*void_init_board
 *
 */ 

void init_board(char board[NUM_ROWS][NUM_COLS])
{ 
int k = 1;
int m = 1; 
//placing blue pieces 
for (char x=1; x <= (NUM_ROWS-2)/2; x++){
	for (char y=1; y <= NUM_COLS; y++){
		if(k == 1)
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
 * NOT REALLY TESTED 
 */ 

unsigned int place_piece(char board[NUM_ROWS][NUM_COLS], char player, 
			unsigned int row, unsigned int col)
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




/*area_and_perimeter
 * 
 */ 
void area_and_perimeter(double height, double length, double *area_p, double *perimeter_p)
{ 

*area_p = height * length;  
*perimeter_p = (2*height) + (2*length);  

}  

/*remove_max_in_out
 *
 *
 */ 
int remove_max_in_out(int array[], unsigned int *length)
{
	int max = 0;
	//finding the max 
	for (int x=0; x<*length; x++){
		if(array[x] > max){
			max = array[x]; 
		}		

	}
	//replacing all instances of the max
	int pos_write_index = 0;     
	for (int checkIndex=0; checkIndex<*length; checkIndex++){
		while (array[checkIndex] == max && checkIndex < *length){
			checkIndex++;
		}
		if (checkIndex < *length){
			array[pos_write_index] = array[checkIndex];
			pos_write_index++; 
		} 
	}
	*length = pos_write_index;
 	for (int x=0; x<*length; x++){
        }
	return max; 
} 


 
