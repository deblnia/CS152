#include <stdio.h>
#include <stdlib.h>
#include "hw4_provided.h"
#include "warmup4.h"

/* count_vowels
 * search through str and count the number of vowels.
 * input: char str - a string
 * output: int - the number of vowels in the string str
 */
int count_vowels(char *str)
{
	int vowels = 0;  
	for (int i = 0; str[i] != '\0'; ++i) {
        	if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
           	 str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
           	 str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
           	 str[i] == 'U') {
           		 ++vowels;
		} 
	}
	printf("count_vowels = %d\n", vowels);  
	return vowels; 
}

/* make_lowercase
 * modify str such that all alphabetic characters are lower case
 * input: char str - a string
 * output: no return value - str is out parameter
 */
void make_lowercase(char *str)
{
	int c = 0;
   	while (str[c] != '\0') {
     		 if (str[c] >= 'A' && str[c] <= 'Z') {
        		 str[c] = str[c] + 32; 
			printf("make_lowercase - str[c] = %c\n", str[c]); 
      		}	
     	 c++;
   	}	
	 printf("final string - %s\n", str); 	
}

/* make_horizontal_stripes
 *   This produces an image stored in the red, green, and blue 2-d arrays.
 *   The image contains black and colored stripes. All stripes are 
 *   stripe_height. The stripe colors are indicated by stripe_color.
 *   The top stripe is colored. The image is heightxwidth.
 * inputs: 
 *   unsigned int red[ROWS][COLS],  - red component of resulting image pixels
 *   unsigned int green[ROWS][COLS], - green component of resulting image pixels
 *   unsigned int blue[ROWS][COLS],  - blue component of resulting image pixels
 *   unsigned int stripe_height,  - height of a single stripe
 *   unsigned int stripe_red,  - red component of stripe pixel
 *   unsigned int stripe_green,  - green component of stripe pixel
 *   unsigned int stripe_blue,  - blue component of stripe pixel
 *   unsigned int width,  - width of resulting image
 *   unsigned int height); - height of resulting image
 * 
 */
void make_horizontal_stripes( 
	unsigned int red[ROWS][COLS], 
	unsigned int green[ROWS][COLS], 
	unsigned int blue[ROWS][COLS], 
	unsigned int stripe_height, 
	unsigned int stripe_red, 
	unsigned int stripe_green, 
	unsigned int stripe_blue, 
	unsigned int width, 
	unsigned int height)
{
	//checking board size consistency
	if(width > ROWS || height > COLS){
		printf("ERROR: width and height \
			 must be less than 50."); 
	}
	//iterate through grid 
  	for(int row  = 0; row < height; row++){
		for(int col = 0; col < width; col++){
			// entire picture black 
			if(stripe_height = 0){		
				red[row][col] = 0; 
				green[row][col] = 0; 
				blue[row][col] = 0;
			}
			//if row is odd, color black
			if(row % 2 == 1){ 		
				red[row][col] = 0; 
				green[row][col] = 0; 
				blue[row][col] = 0;
			}
			else{ //if row is even, color specified 
				red[row][col] = stripe_red; 
				green[row][col] = stripe_green; 
				blue[row][col] = stripe_blue;
			}
		} 
	} 
}

/* make_checker_board
 *   This produces an image stored in the red, green, and blue 2-d arrays.
 *   The image contains white and colored squares. All squares are 
 *   square_width x square_width. The square colors are indicated by 
 *   square_color. The image is heightxwidth. The top-left square is colored.
 * inputs: 
 *   unsigned int red[ROWS][COLS],  - red component of resulting image pixels
 *   unsigned int green[ROWS][COLS], - green component of resulting image pixels
 *   unsigned int blue[ROWS][COLS],  - blue component of resulting image pixels
 *   unsigned int square_height,  - height of a single square
 *   unsigned int square_red,  - red component of square pixel
 *   unsigned int square_green,  - green component of square pixel
 *   unsigned int square_blue,  - blue component of square pixel
 *   unsigned int width,  - width of resulting image
 *   unsigned int height); - height of resulting image
 * 
 */
void make_checker_board( 
        unsigned int red[ROWS][COLS],
        unsigned int green[ROWS][COLS],
        unsigned int blue[ROWS][COLS],
        unsigned int square_width,
        unsigned int square_red,
        unsigned int square_green,
        unsigned int square_blue,
        unsigned int width,
        unsigned int height)
{
	if(width > COLS || height > ROWS){
		printf("ERROR: width and height \
			 must be less than 50."); 
	}
	//iterate through grid 
  	for(int row  = 0; row < height; row++){
		for(int col = 0; col < width; col++){ 
			if(square_width >  0){	
				//if row is odd, check col
				if(row % 2 == 1){ 
					//if col is odd, color 
					if(col % 2 == 1)
					{ 				
						red[row][col] = square_red; 
						green[row][col] = square_green; 
						blue[row][col] = square_blue;
					} 
					//if col is even, white 
					else{
						red[row][col] = 255; 
						green[row][col] = 255; 
						blue[row][col] = 255; 
					}
				}
				//if row is even, check col 
				else{
					//if col is odd, white 
					if(col % 2 == 1)
					{ 				
						red[row][col] = 255; 
						green[row][col] = 255; 
						blue[row][col] = 255;
					} 
					//if col is even, color 
					else{
						red[row][col] = square_red; 
						green[row][col] = square_green; 
						blue[row][col] = square_blue; 
					}

				}
			}
			else{ 
			//entire picture is white  
				red[row][col] = 255; 
				green[row][col] = 255; 
				blue[row][col] = 255;

			}
		}
	}
}
	
