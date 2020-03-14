#include <stdlib.h>
#include <stdio.h>
#include "warmup2.h"

/* print_asterisk_letter
 * input: char letter - the letter to print out
 * output: nothing returned, just printed to the screen.
 * Given a character, print the corresponding upper-case letter of the 
 * alphabet using asterisks. The letter can be anything from 'N' to 'R'. 
 */
void print_asterisk_letter(char letter)
{ 
	if (letter == "S"){
printf(
	"\t****\n"
	"*\t\t\t\t\n"
	"\t***\t\n" 
	"\t\t\t\t*\n"
	"****\t\n");	
} if(letter == "T"){
printf(
	"*****\n" 
	"\t\t*\t\t\n"	
	"\t\t*\t\t\n"
	"\t\t*\t\t\n"
	"\t\t*\t\t\n");
} if (letter == "U"){
printf(
	"*\t\t\t\t*\n"	
	"*\t\t\t\t*\n"	
	"*\t\t\t\t*\n"	
	"*\t\t\t\t*\n"	
	"*\t\t\t\t*\n"
	"\t***\t\n");
} else{
printf(	
	"*\t\t\t\t*\n"	
	"*\t\t\t\t*\n"	
	"*\t\t\t\t*\n"	
	"\t*\t\t*\t\n"	
	"\t*\t\t*\t\n"	
	"\t***\t\n");  
	}

/* draw_hourglass_rec_helper
 * draws a hourglass with asterisks. implemented recursively.
 * inputs:
 *   uint height - the number of rows to print of the wedge
 *   uint offset - amount of spaces that should be to the left of this hourglass
 * outputs:
 *   nothing returned, just printed to the screen
 */

//void draw_hourglass_rec_helper(unsigned int height, unsigned int offset)
//{ 
	
 
//}

void draw_single_row_of_hourglass(unsigned int num_spaces, unsigned int asterisk)
{
        for (int x=0; x < num_spaces; x++)
                fprintf(stdout, " ");
              //print asterisk
				for (int x=0; x < num_asterisk; x++)
                 fprintf(stdout, "*");
        fprintf (stdout,"\n")
}

void draw_hourglass_rec_helper2(unsigned int height, unsigned int offset, unsigned int asterisk, unsigned int curr_row)
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
      			draw_single_row_of_hourglass(offset, asterisk);
   	 	 		  cur_row++;
   			}
      	//top half of hourglass
    	  if (cur_row <= mid_point){
      	offset=offset+1;
        asterisk=asterisk-2;
    	  }
      	else { //bottom half of hourglass
        	offset=offset-1;
       	 	asterisk=asterisk+2;
     	 }
     	 draw_hourglass_rec_helper2(height, offset, asterisk, curr_row);
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
	int mid_point = height/2;
        int num_spaces=0;
        int num_asterisk=0;
   			int curr_row = 1;

    			//when the height is odd, hourglass only has one midpoint with one star
          if (height % 2 != 0) {
            num_asterisk = height;
            draw_hourglass_rec_helper2(height, num_spaces, num_asterisk,curr_row);
          } else { //when the height is even, hourglass has two midpoints with one star in each row
      		 	num_asterisk = height-1;
  					draw_hourglass_rec_helper2(height, num_spaces, num_asterisk,curr_row);
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
  //check for edge cases
        if (height <= 0){
          fprintf(stderr, "Height needs to be a positive number(greater than 0)");
  
	}if (height <3 ){
          fprintf(stderr, "*");
          fprintf (stderr, "\n")
        }if (height == 2 ){
          fprintf(stderr, "*");
          fprintf (stderr, "\n")
        }if(height < 3){
   		 return;
  	}

   	int mid_point = height/2;
        int num_spaces=0;
        int num_asterisk=0;
/*  
  
  //when the height is odd, hourglass only has one midpoint with one star 
          if (height % 2 != 0) {
            num_asterisk = height;
            // upper triangle 
            for (int curr_row = 1; curr_row <= mid_point; cur_row++){
              if (curr_row > 1) {
                num_space++;
                num_asterisk=num_asterisk-2;
              }
              //print spaces
              for (int x=0; x < num_spaces; x++)
                fprintf(stdout, " ");
              //print asterisk
	      for (int x=0; x < num_asterisk; x++)
                 fprintf(stdout, "*");
              	 fprintf (stdout,"\n")
            } 
          // lower triangle 
	  for (int curr_row = mid_point+1; curr_row <= height; cur_row++){
                num_space--;
                num_asterisk=num_asterisk+2;
              //print spaces
            for (int x=0; x < num_spaces; x++)
                fprintf(stdout, " ");
              //print asterisk
	    for (int x=0; x < num_asterisk; x++)
              fprintf(stdout, "*");
              fprintf (stdout,"\n")
            } 
	  }else { //when the height is even, hourglass has two midpoints with one star in each row 
      		 num_asterisk = height-1;
           // upper triangle 
            for (int curr_row = 1; curr_row <= mid_point; cur_row++){
              if (curr_row > 1) {
                num_space++;
                num_asterisk=num_asterisk-2;
              }
              //print spaces
              for (int x=0; x < num_spaces; x++)
                fprintf(stdout, " ");
              //print asterisk
	      for (int x=0; x < num_asterisk; x++)
                 fprintf(stdout, "*");
              fprintf (stdout,"\n")
            } 
            //2nd midpoint of hour glass with one *
            //print spaces
            for (int x=0; x < num_spaces; x++){
            	fprintf(stdout, " "); 
              //print asterisk
            fprintf(stdout, "*");
            fprintf (stdout,"\n")
	    }
          // lower triangle 
            for (int curr_row = mid_point+2; curr_row <= height; cur_row++){
                num_space--;
                num_asterisk=num_asterisk+2;
              //print spaces
              for (int x=0; x < num_spaces; x++)
                fprintf(stdout, " ");
              //print asterisk
	    for (int x=0; x < num_asterisk; x++)
                 fprintf(stdout, "*");
              fprintf (stdout,"\n")
          }
	  }

        return;
*/ 
}
