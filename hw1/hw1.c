/* Deblina Mukherjee, deblina */ 
/* CS 152, Winter 2020 */
/* hw1 */  


#include <stdio.h>
#include <stdlib.h>

/* convert_length
 * convert length from centimeters to inches
 * inputs:
 *    double centimeters
 * return value:
 *    double - the same number converted to inches
 */
double convert_length(double centimeters)
{	// Choosing btw. negative input (invalid) or doing conversion
	if (centimeters < 0) { 
		return -1;
	}
	else 
		return centimeters*0.3937;
}
/* trapezoid_area
 * calculate the area of a trapezoid
 * inputs:
 *   unsigned int height - height of the trapezoid
 *   unsigned int base1 - length of base 1 of the trapezoid
 *   unsigned int base2 - length of base 2 of the trapezoid
 * return value:
 *   double - calculated area of the trapezoid
 */
double trapezoid_area(unsigned int height, unsigned int base1,\
			 unsigned int base2)
{	//Choosing btw. input of 0 (invalid) or calculating area 
	if (height == 0 || base1 == 0 || base2 == 0)
{	
		fprintf(stderr,"ERROR:No inputs to trapezoid_area can be 0\n");
		return 0;
}
	else
		return ((base1 + base2)/2)*height;
}
/* print_number_triangle
 * print out the first 5 rows of a number triangle 
 * inputs:
 *    unsigned int start_num
 * return value:
 *    none - output is printed to the screen
 * output
 *    print out the first 5 rows of a number triangle
 */
void print_number_triangle(unsigned int start_num)
{	//Choosing btw. number of more than 3 digits and printing triangle 

	if (1*start_num > 99 || 2* start_num > 99 || 3 * start_num > 99 ||
		4*start_num > 99 || 6*start_num > 99)
	{
		fprintf(stderr, "ERROR: No numbers in the triangle can be 3"
			" digits or more.\n"); 
	}
 	
	else
	{
		
		fprintf(stderr,"\t\t\t\t%3d\n"
		       "\t\t\t%3d\t\t%3d\n" 
		       "\t\t%3d\t\t%3d\t\t%3d\n" 
		       "\t%3d\t\t%3d\t\t%3d\t\t%3d\n" 
			"%3d\t\t%3d\t\t%3d\t\t%3d\t\t%3d\n", 
		1*start_num,1*start_num, 1* start_num,1*start_num,
		2* start_num,1*start_num,1*start_num,3 * start_num,
		3*start_num,1*start_num,1*start_num,4*start_num,6*start_num,
		4*start_num,1*start_num);  
 	}
}

/***********************************************************
********** PLACE OTHER TEST FUNCTIONS HERE *****************
***********************************************************/

/* test_convert_length
 * This tests the convert_length function
 * inputs:
 *    double centimeters - centimeters to convert
 *    double expected - expected result
 *    double wiggle_room - amount result can be wrong
 * outputs:
 *    unsigned int success - 0 for failure, 1 for success
 */
unsigned int test_convert_length(double centimeters, double expected,\
				 double wiggle_room)
{
	double result = convert_length(centimeters);
	// notice we don't compare a double or float with ==
	if ((result >= expected - wiggle_room) &&
	    (result <= expected + wiggle_room))
	{
		printf("convert_length(%f) = %f. Success\n",
			centimeters, result);
		return 1;
	}
	else
	{
		printf("convert_length(%f) = %f. Expected %f. FAILURE\n",
			centimeters, result, expected);
		return 1;
	}

}
/* test_area_trapezoid
 * This tests the area_trapezoid_function
 * input: 
 *   unsigned int height - height 
 *   unsigned int base1 - base of triangle 
 *   unsigned int base2 - other base of triangle 
 *   double expected - expected area value 
 *   double wiggle_room - range of deviation 
 * output: 
 *   No return value. Prints info, calls function, returns. 
 *  
*/ 
void test_trapezoid_area(unsigned int height, unsigned int base1,\
 		unsigned int base2, double expected, double wiggle_room) 
{

	double  result = trapezoid_area(height, base1,base2); 
	//Choosing btw. return value within acceptable margin of error or not   
	if ((result >= expected - wiggle_room) &&
	    (result <= expected + wiggle_room))
	{
		printf("area_trapezoid(%u, %u, %u) = %f. Success\n",
			height, base1, base2, result);
	}
	else
	{
		printf("area_trapezoid(%u, %u, %u) = %f. Expected %f."
		" FAILURE\n",
			height, base1, base2, result, expected);
	}
} 
/* test_print_number_triangle
 * This tests the print_number_triangle function
 * input:
 *   unsigned int start_num - top of triangle
 * outputs:
 *   No return value. Prints info, calls function, returns.
 */
void test_print_number_triangle(unsigned int start_num)
{
	printf("number triangle: %d\n", start_num);
	print_number_triangle(start_num);
	printf("\n\n");

}

/***********************************************************
********** ONLY MAIN GOES BELOW THIS POINT *****************
***********************************************************/

int main()
{

	double result;
	/* These calls check functions with test cases. */

	test_convert_length(100, 39.37, 0.01); //large 
	test_convert_length(10,3.937, 0.01); //middle 
	test_convert_length(1,0.3937,0.01); //base case  
	test_convert_length(-10,-1,0.1); //if statement 	

	test_trapezoid_area(50,50,50,2500, 0.01); //large
	test_trapezoid_area(10,10,10,100,0.01); //middle
	test_trapezoid_area(15,10,10,150, 0.01); 
	test_trapezoid_area(10,12,10,110,0.01); 
	test_trapezoid_area(10,10,12,110,0.01);   
	test_trapezoid_area(1,1,1,1,0.01); //base case 
	test_trapezoid_area(1,0,1,0,0.01);//if statement       

	test_print_number_triangle(15);//large 
	test_print_number_triangle(3);//middle  
	test_print_number_triangle(0);//base
	test_print_number_triangle(20);//if statement   
}
