#include <stdio.h>
#include <stdlib.h>
#include "mastermind.h"
#include <math.h> 


/* extract_digit
 * extracts specific digit from given integer 
 * inputs: 
 * 	uint pattern - the given digit 
 * 	uint digit - the digit to be extracted 
 * outputs: 
 * 	uint extracted digit 
 */
unsigned int extract_digit(unsigned int pattern, unsigned int digit)
{
	int temp,factor, result=1;

  	temp=digit+1;
  	while(temp){
      	temp--;
     	factor = factor*10;
  	}
     result = pattern % factor;
     printf("extract_digit - pattern=%d, digit=%d, result=%d",pattern, digit,result);
     return result;
}

/*num_of_color
 * The number of instances of a color in the pattern  
 * inputs: 
 * 	uint pattern - given pattern 
 * 	uint color - color we're looking for 
 * output: 
 * 	a number between 0 and 4 - count of the number of instances of color 
 * 	seen in the pattern 
 */
unsigned int num_of_color(unsigned int pattern, unsigned int color)
{
    unsigned int num_color=0;
  
    for (int x=0; x < 4; x++) {
    if (extract_digit(pattern, x) == color)
      num_color++;
  }
  printf("num_of_color - pattern=%d, color=%d,num_color=%d", pattern, color, 
		  num_color);
	return num_color;
}

/* count_exact_matches
 * count how many digits in guess match both in color and position as compared 
 * to the solution 
 * inputs: 
 * 	guess: code guesssed by user 
 * 	solution: code created by codemaker/program/random number generator
 * outputs: 
 * 	a number between 0 and 4 - count of number of digits that match both 
 * 	color and position of guess and solution
 */ 
unsigned int count_exact_matches(unsigned int guess, unsigned int solution)
{

  unsigned int num_exact_match=0;
  
  for (int x=0; x < 4; x++) {
  if (extract_digit(solution, x) == extract_digit(guess,x))
      num_exact_match++;
  }
  printf("count_exact_matches - guess=%d, solution=%d,num_exact_match=%d", 
		  guess, solution, num_exact_match);
	return num_exact_match; 
}

/* count_color_matches
 * count how many digits in guess match in color, regardless of position, 
 * as compared to the solution 
 * inputs: 
 * 	guess - code guessed by user 
 * 	solution - code created by random number generator 
 * output: 
 * 	a number between 0 and 4 - count of the number of digits that match 
 * 	both the between   
 *
 */ 	
unsigned int count_color_matches(unsigned int guess, unsigned int solution)
{
  unsigned int num_color_matches=0;
  unsigned int color_to_compare=0;
  
  for (int x=0; x < 4; x++) {
    color_to_compare=extract_digit(guess,x);
    num_color_matches=num_color_matches+num_of_color(solution, color_to_compare);
  }
  if (num_color_matches> 4)
    num_color_matches=4;
  printf("count_color_matches - guess=%d, solution=%d,num_color_match=%d", 
	guess, solution, num_color_matches);
  return num_color_matches;
}

/* get_guess_feedback
 * This function prepares the feedback by determining whether a guess was correct or not.
 * Input - 
 * 	guess : code guessed by user
 * 	solution : code created by codemaker/program/random number generator
 * Output - 
 * 	feedback : a 2 digit number, each digit could have a value between 
 * 	    0 and 4. The 1st digit provides the number of exact matches of 
 * 	    color and position between the guess and the solution. The 2nd 
 * 	    digit provides the number of instances of matched color between 
 * 	    the guess and the solution
 */ 
unsigned int get_guess_feedback(unsigned int guess, unsigned int solution)
{
  unsigned int feedback=0;
  unsigned int temp=guess;
  if (temp/10000 != 0) {
    printf("Your guess, %d, is not a 4 digit number\n", guess);
    return 100;
	}
  if (extract_digit(guess, 0) > 6 || extract_digit(guess, 1) > 6 || 
		  extract_digit(guess, 2) > 6|| extract_digit(guess, 3) > 6 ||
      extract_digit(guess, 0) < 1 || extract_digit(guess, 1) < 1 || 
      extract_digit(guess, 2) < 1|| extract_digit(guess, 3) < 1 ) {
      	printf("Your digit of your guess, %d, must be between 1 and 6\n", guess);
    return 100;
	}
  unsigned int exactMatch=count_exact_matches(guess, solution);
  unsigned int colorMatch=count_color_matches(guess, solution);
  
  feedback=(exactMatch*10)+colorMatch;
  printf("get_guess_feedback - guess=%d, solution=%d, exactMatch=%d, colorMatch=%d, feedback=%d", guess, solution, exactMatch, colorMatch, feedback);
  return feedback;
}


// TODO: Write a test function for each mstermind function

/* test_mastermind
 * This is the test function that has 3+ good test cases for this function in your
 * mastermind program. This verifies that the bits are working so that if you find a 
 * bug you can more easily localize it.
 * inputs:
 *   none. Tests are hard coded.
 * outputs:
 *   none. Test results are printed out.
 */
void test_mastermind()
{

	unsigned int solution = 0;
	unsigned int feedback = 0;
  	int guess = 0;
  

	solution = get_new_code();
	printf("solution: %u\n",solution);

  //Check exact match
  feedback=get_guess_feedback(solution, solution);
  
  //Check  color match without regard to position
  guess=solution;
  guess=(solution/10)+5;
  feedback=get_guess_feedback(guess, solution);
    
  //Check invalid digit in guess  
  guess=8654;
  feedback=get_guess_feedback(guess, solution);
}

/* print_mastermind_instructions
 * This prints out user instructions to play mastermind.
 * inputs:
 *   none
 * outputs:
 *   none. Insructions are printed to screen.
 */
void print_mastermind_instructions()
{
	printf("Welcome to mastermind. I am thinking of a 4-number\n");
	printf("sequence. All four numbers are between 1 and 6.\n");
	printf("You have 12 guesses to guess it correctly.\n");
	printf("Each time you guess, I'll tell two things.\n");
	printf("1. How many numbers are correct and in the correct position.\n");
	printf("2. How many other numbers are correct but in the wrong position.\n");
	printf("Let's get started!!!\n");
}

/* get_new_code
 * Generates a 4-digit number, with each digit a number from 1 to 6, inclusive.
 * inputs:
 *   none
 * outputs:
 *   unsigned int - 4-digit number with each digit from 1 to 6
 */
unsigned int get_new_code()
{
	int i;
	int result = 0;
	for (i = 0; i < 4; i++)
	{
		result = result * 10;
		result = result + ((rand() % 6) + 1);
	}
	return (unsigned int)result;
}


/* play_mastermind
 * This is the game loop to play mastermind. All print statements are provided so that you 
 * have consistent messages for grading purposes. An example of how to do error checking is 
 * provided so you can model that.
 * inputs:
 *  none. Users play interactively
 * outputs:
 *  none. Everything is printed.
 */
void play_mastermind()
{

	unsigned int guess_num = 0;
	unsigned int solution = 0;
	unsigned int guess = 0;
	unsigned int feedback = 0;
	
	unsigned int won=0;

	print_mastermind_instructions();
	solution = get_new_code();
	// print this out so that we can tell whether yours matches ours. Don't remote
	printf("solution: %u\n",solution);

  	//MAKES GUESS_NUM=12 when ONE GUESS WORKS
  	guess_num = 1;
  	while (guess_num > 0) {
		printf("Guess %d - ",guess_num);
    		printf("Input your 4-digit guess: ");
		scanf("%u",&guess);

		feedback=get_guess_feedback(guess, solution);

    		if (feedback != 100) {
			// report the feedback
			printf("Feedback: %u correct placement, correct color,\n",
				feedback / 10);
			printf("%u incorrect placement, correct color\n",
				feedback % 10);
   		 } else {
			// note: If it's an invalid guess, go back and ask the guess immediately. Go back
			// to Guess %d - . Don't print out the Congratuations or Not quite below.
			printf("%u is an invalid guess. Make sure your guess is a 4-digit number,"
			"each digit between 1-6.\n", guess);
   		} 
		
		if (feedback/10 == 4) {
		// if correct, print out congrats and return from this function.
			printf("Congratulations! Your guess of %u was correct!\n",
			guess);
      			guess_num = 0;
   		} else if (feedback != 100) {
		// if incorrect
      			guess_num--;
			printf("Not quite - you still have %u guesses left!\n",
				guess_num);
    		}
	}
	// only print this out if they ran out of guesses didn't win.
  	if (won==0)
	printf("Sorry, you did not guess it! The solution was %u\n",solution);
}
