#include <stdio.h> 
#include <stdlib.h> 
#include "warmup5_provided.h" 
#include "warmup5.h" 

int main()
{

//testing safe_str_concat 
char str1[] = "hello ";
char str2[] = "there";
char *result;  

result = safe_str_concat(str1,str2); 

char str3[] = "\0";
char str4[] = "\0";

result = safe_str_concat(str3,str4); 

char str5[] = "hello ";
char str6[] = "\0";

result = safe_str_concat(str5,str6);

//testing int_vector initialization 
int_vector *result2; 
result2 = make_init_array(); 

//testing write_value 
write_value(result2,10,10); 
printf("result2 len - %d\n", result2->allocated_size);
write_value(result2, 5,5); 
printf("result2 len - %d\n", result2->allocated_size);
write_value(result2, 32,33); 
printf("result2 len - %d\n", result2->allocated_size);

//testing read_value 
int read_val_result; 
read_val_result = read_value(result2, 2); 
printf("result - %d\n", read_val_result); 
read_val_result = read_value(result2, 5); 
printf("result - %d\n", read_val_result); 
read_val_result = read_value(result2, 3); 
printf("result - %d\n", read_val_result); 


//test make_and_init_image 
pixel pic_color;
pixel** result_picture; 
pic_color.red = 100;
pic_color.green = 100; 
pic_color.blue = 100;  
  
result_picture = make_and_init_image(2,2,pic_color); 
provided_write_png_struct("testwarmup5.png", result_picture, 2,2); 

result_picture = make_and_init_image(20,20,pic_color); 
provided_write_png_struct("testwarmup5.png", result_picture, 20,20); 

result_picture = make_and_init_image(200,200,pic_color); 
provided_write_png_struct("testwarmup5.png", result_picture, 200,200); 

} 
