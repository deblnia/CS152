#include <stdio.h> 
#include <stdlib.h> 
#include "hw5.h" 

/* 
int main(int argc, char *argv[])

   int func_to_run = 0;
   char *str;
 
   if( argc < 2 ) {
      printf("The argument supplied is %s\n", argv[1]);
   }
   else {
      func_to_run = atoi(argv[1]);
      printf("Function Running: %d\n", func_to_run);
      switch (func_to_run)
	{	
    	case 1: // make_string, one inpu
	printf("in case 1 \n"); 
		if(argc >= 3) 
		{
			printf("first line of if\n"); 
			safe_string* result1; 
			printf("before str[100]\n");
			str = (char*)malloc(sizeof(char)*100);
			str[0] = '\0';  
			strcat(str,argv[3]);   
			printf("str:%s\n", str); 
			result1 = make_string(str);
			printf("result1->str: %s, \
			result1->allocated_length:%d\n", result1->str, \
			result1->allocated_length);
		} 
		else
			printf("Please provide all arguments.\n"); 
        	break;
    	case 2: // safe_str_cpy, 2 inputs 
        	break;
    	default: // code to be executed if function not recognized 
		printf("Unrecognized function number. Please choose \
			a valid number..\n"); 
	} 
   }
*/ 
int main()
{
//TESTING MAKE_STRING  
safe_string* result1; 
char str[15] = "hello world";  
result1 = make_string(str);
printf("result->str: %s, \
result->allocated_length:%d\n", result1->str, result1->allocated_length);

safe_string* result2; 
char another_str[15] = "hello";  
result2 = make_string(another_str);
printf("result->str: %s, \
result->allocated_length:%d\n", result2->str, result2->allocated_length);

safe_string* result15; 
char another_other_str[15] = "hi";  
result15 = make_string(another_other_str);
printf("result->str: %s, \
result->allocated_length:%d\n", result15->str, result15->allocated_length);



//TESTING SAFE_STR_CPY 
safe_string* result3; 
char str3[15] = "hello";  
result3 = make_string(str3);

safe_str_cpy(result3, result1);
printf("AFTER SAFE STR COPY: result->str: %s, \
result->allocated_length:%d\n", result3->str, result3->allocated_length);  

safe_string* result30; 
char str_other[15] = "hi";  
result30 = make_string(str_other);

safe_str_cpy(result30, result1);
printf("AFTER SAFE STR COPY: result->str: %s, \
result->allocated_length:%d\n", result30->str, result30->allocated_length);  





//TESTING SAFE_STR_CAT 
printf("TESTING safe_str_cat:"); 
safe_str_cat(result3,result1); 
printf("AFTER SAFE STR CAT: result3->str: %s, \
result3->allocated_length:%d\n", result3->str, result3->allocated_length); 


//TESTING SAFE_STR_CHR
char str4 = 'h';
char *result10;  
result10 = safe_strchr(result3, str4); 
printf("result %p\n", result10); 


//TESTING SAFE_STR_CMP
safe_string *s1 = "hello"; 
safe_string *s2 = "hallo"; 
int strcmp_result; 
strcmp_result = safe_strcmp(result3, result1); 
printf("String Comparison result: %d\n", strcmp_result); 


}
