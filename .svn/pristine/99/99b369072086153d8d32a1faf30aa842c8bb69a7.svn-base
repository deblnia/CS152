#include <stdio.h>                                                              
#include <stdlib.h>

#include <string.h>
                                                             
#include "warmup5_provided.h"                                                       
#include "warmup5.h" 
int_vector *new_vector;

/* safe_str_concat
 * inputs: 
 * 	char *str1 - character pointer to str1 
 * 	char *str2 - character pointer to str2
 * outputs: 
 * 	none - allocates new string to hold both str1 and str2 
 */ 
char *safe_str_concat(char *str1, char *str2)
{	
	char *final_string;
	int len_str1; 
	int len_str2;   
	len_str1 = strlen(str1); 
	len_str2 = strlen(str2); 
	final_string = (char*)(malloc((sizeof(char) * (len_str1 + len_str2))));
	strcpy(final_string, str1); 
	strcpy(final_string+len_str1, str2);  
	return final_string;
}

/* make_init_array
 * allocates the init_vector and initializes the values for an array with 0 
 * items. 
 * input: 
 * 	none. 
 * output: 
 * 	int_vector *  
 */ 
int_vector* make_init_array()
{
	//int_vector *new_vector;
	new_vector = (int_vector*)malloc(sizeof(int_vector)); 
	new_vector->allocated_size = 0;
	new_vector->array = NULL; 
	return new_vector; 
}

/* write_value
 * ASSUME WRITE TO SOME INDEX GREATER THAN 1 
 * inputs: 
 * 	int_vector *vector - vector to write to 
 * 	uint index - index to write to 
 * 	int value - value to place in index 
 * output: 
 * 	none. void 
*/ 
void write_value(int_vector *vector, unsigned int index, int value)
{ 
	int len_array; 
	int *tmp_array; 
	int new_len; 
	len_array = vector->allocated_size;
	new_len = len_array; 
	
	//trying to write to index that does not have alloc. memory 
	if(index > len_array)
	{ 
		if(index > len_array*2 && index > 16)
		{
			tmp_array = (int*)(malloc(sizeof(int) * index));
			new_len = index; 
		} 
		else if(len_array*2 >= index && index >= 16)
		{
			tmp_array = (int*)(malloc(sizeof(int) * len_array*2));
			new_len = len_array*2;  
		} 
		else if(index < 16)
		{  
			tmp_array = (int*)(malloc(sizeof(int) *16));
			new_len = 16; 
		} 
		//copying over old array
		int i; 
		for(i=0; i < len_array; i++) 
		{	 
				tmp_array[i] = vector->array[i]; 
		}
		//only free if there is something to free 
 	 	if(vector->allocated_size > 0)
		{	
	 		//free old 
			free(vector->array); 
		} 
		//updating struct 
		vector->array = tmp_array; 
		vector->allocated_size = new_len;  
	}
	
	vector->array[index] = value;
 
} 
/* read_value
 * read value in int_vect 
 * inputs: 
 * 	int_vector *vector
 * 	uint index - index to read from 
 * outputs: 
 * 	int (item at that index) 
 */ 
int read_value(int_vector *vector, unsigned int index)
{ 	
	int len_array; 
	len_array = vector->allocated_size; 
	
	if(index > len_array)
	{
		return 0; 
	} 
	else
	{
		printf("index value %d\n", vector->array[index]);  
		return vector->array[index]; 
	} 
} 

/*pixel** make_and_init_image(int height, int width, pixel color)
 * makes and initializes image 
 * inputs: 
 * 	int height - height of image in pixels 
 * 	int width - width of image in pixels 
 * 	pixel color - pixel specifying colors 
 * outputs: 
 * 	pointer to pointer to pixel type 
 */ 
pixel** make_and_init_image(int height, int width, pixel color)
{
	pixel** pic; 		
	pic = (pixel**)malloc(sizeof(pixel*) * height);

	int i,j; 
	for(i=0; i < height; i++)
	{ 
		pic[i] = (pixel*) malloc(sizeof(pixel) * width); 
		for(j=0; j < width; j++)
		{ 
			pic[i][j].red = color.red; 
			pic[i][j].green = color.green; 
			pic[i][j].blue = color.blue;
		}
	}
	return pic; 
} 
