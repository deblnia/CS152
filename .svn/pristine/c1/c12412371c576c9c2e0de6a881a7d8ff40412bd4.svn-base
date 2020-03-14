#include <stdio.h>
#include <stdlib.h>
#include "hw4_provided.h"
#include "warmup4.h"

int main()
{
	// declare variables
	unsigned int r[ROWS][COLS];
        unsigned int g[ROWS][COLS];
        unsigned int b[ROWS][COLS];
        unsigned int width;
        unsigned int length;

	char str1[] = {'H','o','w','d','y',' ','T','H','E','R','E','!','\0'};
	count_vowels(str1);

	make_lowercase(str1);

	char str2[] = {'H', 'E','L','L','O',' ','T', 'h', 'e', 'r','e','\0'};   
	count_vowels(str2);

	make_lowercase(str2);
	
	char str3[] = {'h','e','l','l','o',' ', 't', 'h','e','r','e','\0'}; 
	
	count_vowels(str3); 
	
	make_lowercase(str3); 

/*
	// read in ppm file
	// note that r, g, b, width, length are all out parameters
	// that means we need to declare the variables here and send
	// the locations to the function, as seen below.

	// note that for the warmup, you do not need to read in a png.
	//provided_read_png("sample.png",r,g,b,&width,&length);
*/

// put in arrays
	//make_horizontal_stripes(r, g, b, 1, 30, 144, 255, ROWS, COLS);
	make_horizontal_stripes(r, g, b, 1, 30, 144, 255, 3, 3);
	// print to html to view
	// print to html to view
	provided_print_image_to_html("my_horiz_stripes.html",r,g,b,12,12);

	// put in arrays
	make_checker_board(r,g,b,4,30,144,255, 12, 12);
	// print to html to view
	provided_print_image_to_html("my_checkboard.html",r,g,b,12, 12);

}
