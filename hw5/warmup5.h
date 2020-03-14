#ifndef WARMUP5_H 
#define WARMUP5_H 
#include "warmup5_provided.h" 
/* safe_str_concat
 * inputs: 
 * 	char *str1 - character pointer to str1 
 * 	char *str2 - character pointer to str2
 * outputs: 
 * 	none - allocates new string to hold both str1 and str2 
 */ 
char *safe_str_concat(char *str1, char *str2);


typedef struct{
	unsigned int allocated_size;
	int *array;
}int_vector;


/* make_init_array
 * allocates the init_vector and initializes the values for an array with 0 
 * items. 
 * input: 
 * 	none. 
 * output: 
 * 	int_vector *  
 */ 
int_vector* make_init_array();


/* write_value
 * ASSUME WRITE TO SOME INDEX GREATER THAN 1 
 * inputs: 
 * 	int_vector *vector - vector to write to 
 * 	uint index - index to write to 
 * 	int value - value to place in index 
 * output: 
 * 	none. void 
*/ 
void write_value(int_vector *vector, unsigned int index, int value);



/* read_value
 * read value in int_vect 
 * inputs: 
 * 	int_vector *vector
 * 	uint index - index to read from 
 * outputs: 
 * 	int (item at that index) 
 */ 
int read_value(int_vector *vector, unsigned int index);




/*pixel** make_and_init_image(int height, int width, pixel color)
 * makes and initializes image 
 * inputs: 
 * 	int height - height of image in pixels 
 * 	int width - width of image in pixels 
 * 	pixel color - pixel specifying colors 
 * outputs: 
 * 	pointer to pointer to pixel type 
 */ 
pixel** make_and_init_image(int height, int width, pixel color);
 

#endif
