#include <stdlib.h>
#include <stdio.h>
#include "warmup2.h"

/* print_asterisk_letter
 * input: char letter - the letter to print out
 * output: nothing returned, just printed to the screen.
 * Given a character, print the corresponding upper-case letter of the 
 * alphabet using asterisks. 
 */
void print_asterisk_letter(char letter)
{ 
  if (letter == 'S'){
	printf(
        " ****\n"
        "*    \n"
        " *** \n"
        "    *\n"
        "**** \n\n\n\n");
} else if(letter == 'T'){
	printf(
        "*****\n"
        "  *\n"
        "  *\n"
        "  *\n"
        "  *\n\n\n\n");
} else if (letter == 'U'){
	printf(
        "*    *\n"
        "*    *\n"
        "*    *\n"
        "*    *\n"
        " *** \n\n\n\n");
} else if(letter == 'V'){
	printf(
	"*    *\n"
        "*    *\n"
        "*    *\n"
        " *  *\n"
        "   * \n\n\n\n");
} else
	printf("Error: Please enter either S, T, U, or V.\n"); 	
}

/*draw_single_row_of_hourglass
 *
 *
 *
 *
 */ 

void draw_single_row_of_hourglass(unsigned int num_spaces, unsigned int num_asterisk)
{
	//fprintf(stdout, "draw -- num_ast = %d, num_spaces = %d\n", num_asterisk, num_spaces); 
	//print spaces 
        for (int x=0; x < num_spaces; x++)
                fprintf(stdout, " ");
        //print asterisk
        for (int x=0; x < num_asterisk; x++)
        	fprintf(stdout, "*");
	fprintf (stdout,"\n");
}


/* draw_hourglass_rec_helper
 * draws a hourglass with asterisks. implemented recursively.
 * inputs:
 *   uint height - the number of rows to print of the wedge
 *   uint offset - amount of spaces that should be to the left of this hourglass
 *   uint asterisks - number of asterisks 
 *   uint curr_row - number of row 
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_hourglass_rec_helper(unsigned int height, unsigned int offset, unsigned int asterisk, unsigned int curr_row)
{ 
 	int mid_point = height/2;
        int oddHeight=0;
        if (height % 2 != 0)
      		oddHeight=1;

        if (curr_row > height)
        	return;
        else {
		draw_single_row_of_hourglass(offset, asterisk);
        	curr_row++;
		if (oddHeight==0 && curr_row==mid_point+1) { 
		//this is the second midpoint for an even hourglass 
                	draw_single_row_of_hourglass(offset, asterisk);
                	curr_row++;
                } 
        	//top half of hourglass
        	if ((oddHeight ==0 && curr_row <= mid_point)|| 
				(oddHeight == 1 && curr_row <= mid_point+1)){
        		offset=offset+1;
        		asterisk=asterisk-2;
        	}		
		//bottom half of hourglass, if even height then two midpoints, 
		//odd has one midpoint 
		else if ((oddHeight == 1 && curr_row >= mid_point + 2) || 
		  	(oddHeight == 0 && curr_row >= mid_point + 1)){ 
                	offset=offset-1;
                	asterisk=asterisk+2;
        	}	 
	
		draw_hourglass_rec_helper(height, offset, asterisk, curr_row);
     }  


}

/* draw_hourglass_rec
 * draws a hourglass with asterisks. implemented recursively.
 * inputs:
 *   uint height - the number of rows to print of the wedge
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_hourglass_rec(unsigned int height)
{
	//check for edge cases
	fprintf(stdout, "\n\n\n"); 
        if (height <= 0){
        fprintf(stdout, "Height needs to be a positive number(greater than 0). You entered %d\n", height);
	 return; 

        } 
	if (height == 2 ){
          fprintf(stdout, "*\n*");
          fprintf (stdout, "\n");
	  return; 
        }
	if(height == 1){
          fprintf(stdout, "*\n");
	  return;
        }
        int num_spaces=0;
        int num_asterisk=0;
        int curr_row = 1;

    	//when the height is odd, hourglass only has one midpoint 
	//with one star
          if (height % 2 != 0) {
            num_asterisk = height;
            draw_hourglass_rec_helper(height, num_spaces, num_asterisk,curr_row);
          }
          else { //when the height is even, hourglass has two midpoints with one star in each row
	     num_asterisk = height-1;
             draw_hourglass_rec_helper(height, num_spaces, num_asterisk,curr_row);
	  }
	return;	
}

/* draw_hourglass_iter
 * draws a hourglass with asterisks. Implemented iteratively.
 * inputs:
 *   uint height - the number of rows to print of the wedge
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_hourglass_iter(unsigned int height)
{ 
	fprintf(stdout, "\n\n\n"); 
   	//check for edge cases
	fprintf(stdout, "\n\n\n"); 
        if (height <= 0){
          fprintf(stdout, "Height needs to be a positive number(greater than 0). You entered %d\n", height);
	 return; 

        } 
	if (height == 2 ){
          fprintf(stdout, "*\n*");
          fprintf (stdout, "\n");
	  return; 
        }
	if(height == 1){
          fprintf(stdout, "*\n");
	  return;
        }

        int mid_point = height/2;
        int num_spaces=0;
        int num_asterisk=0;

  //when the height is odd, hourglass only has one midpoint with one star
 	if (height % 2 != 0) {
            num_asterisk = height;
            // upper triangle
 	      for(int curr_row = 1; curr_row <= mid_point+1; curr_row++){
              	if (curr_row > 1) {
                	num_spaces++;
                	num_asterisk=num_asterisk-2;
              	}	
              //print spaces
              	for (int x=0; x < num_spaces; x++)
                	fprintf(stdout, " ");
              //print asterisk
              	for (int x=0; x < num_asterisk; x++)
                 	fprintf(stdout, "*");
         	fprintf (stdout,"\n");
           }
          // lower triangle
          for (int curr_row = mid_point+2; curr_row <= height; curr_row++){
                num_spaces--;
                num_asterisk=num_asterisk+2;
              //print spaces
            for (int x=0; x < num_spaces; x++)
                fprintf(stdout, " ");
              //print asterisk
            for (int x=0; x < num_asterisk; x++)
              fprintf(stdout, "*");
            fprintf (stdout,"\n");
            }
          } 
	//when the height is even, hourglass has two midpoints with one star in each row
	  else { 
            num_asterisk = height-1;
           // upper triangle
            for (int curr_row = 1; curr_row <= mid_point; curr_row++){
              if (curr_row > 1) {
                num_spaces++;
                num_asterisk=num_asterisk-2;
              }
              //print spaces
              for (int x=0; x < num_spaces; x++)
                fprintf(stdout, " ");
              //print asterisk
              for (int x=0; x < num_asterisk; x++)
                 fprintf(stdout, "*");
              fprintf (stdout,"\n");
            }
            //2nd midpoint of hour glass with one *
 	    //print spaces
            for (int x=0; x < num_spaces; x++)
                fprintf(stdout, " ");
             //print asterisk
            fprintf(stdout, "*\n");
          // lower triangle
            for (int curr_row = mid_point+2; curr_row <= height; curr_row++){
		num_spaces--;
                num_asterisk=num_asterisk+2;
              //print spaces
              for (int x=0; x < num_spaces; x++)
                fprintf(stdout, " ");
              //print asterisk
              for (int x=0; x < num_asterisk; x++)
              	fprintf(stdout, "*");
              fprintf (stdout,"\n");
            }	
          }

        return;
      
}


