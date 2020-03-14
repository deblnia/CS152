#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "hw5.h" 

/* make_empty_string
 * output: 
 * 	returns empty string initialized with NULL string and length 0 
 */
safe_string* make_empty_string()
{ 
	safe_string* string;
	string = (safe_string*)malloc(sizeof(safe_string)); 
	string->str = NULL;   
	string->allocated_length = 0;
	return string; 
} 

/* make_string
 * makes safe string 
 * inputs: 
 * 	char *str - character pointer to string 
 * outputs: 
 * 	safe_string* - pointer to safe_string type 
 */ 
safe_string* make_string(char *str)
{
	if(str == NULL) 
	{ 
		return make_empty_string(); 
	} 
	else
	{ 
		int str_len;  
		str_len = strlen(str); 
		safe_string* safestr;
		safestr = (safe_string*)malloc(sizeof(safe_string)); 
		safestr->str = (char*)(malloc(sizeof(char) * str_len));
		strcpy(safestr->str, str); 
		safestr->allocated_length = str_len;
	
		return safestr;
	}  
}



/* safe_str_cpy
 * safely copy string 
 * inputs: 
 * 	safe_string *dest - pointer to destination 
 * 	safe_string *src - pointer to source 
 * outputs: 
 * 	none. void
 */  
void safe_str_cpy(safe_string *dest, safe_string *src)
{
	// is the dest big enough to hold the src? 
	unsigned int src_len; 
	src_len = src->allocated_length; 
	if(dest->allocated_length <  src_len)
	{ 
		//reallocate space in dest
		free(dest->str); 
		dest->str = (char*)(malloc(sizeof(char) * src_len));
	}
	//copy source to dest 
	strcpy(dest->str,src->str);  
}


/* safe_str_cat 
 * safely copy string 
 * inputs: 
 * 	safe_string *dest - pointer to destination 
 * 	safe_string *src - pointer to source 
 * outputs: 
 * 	none. void
 */  
void safe_str_cat(safe_string *dest, safe_string *src)
{
	// is the dest big enough to hold the src? 
	unsigned int src_len = src->allocated_length;
	unsigned int dest_len = dest->allocated_length;  
	//reallocate space in dest
	free(dest->str); 
	dest->str = (char*)(malloc(sizeof(char) * src_len));
	//copy source to dest 
	strcat(dest->str,src->str);  


}
/* *safe_strchr
 * safe_strchr returns a pointer that points within the string that s holds
 * inputs: 
 * 	safe_string *s - pointer to safe_string s 
 * 	char c - character to find 
 * outputs: 
 * 	index of first instance of character  
 */
char *safe_strchr(safe_string *s, char c)
{ 
	//if not empty 90% case  
	int i = 0; 
	int found = 0; 
	while(i < s->allocated_length || !found) 
	{
		if(s->str[i] == c);  
		{
			found = 1; 	
		} 
		i++; 
	}
	if(found) 
	{ 
		return &s->str[i];   	
	}
	return NULL; 
} 

/* safe_strcmp
 * safe_strcmp returns 0 if the strings within s1 and s2 are identical,
 * -1 if s1 is earlier alphabetically and 1 if s2 is earlier
 * alphabetically 
 * inputs: 
 * 	*s1 - pointer to safe_string 
 * 	*s2 - pointer to safe_string 
 * outputs: 
 * 	0 if strings are identical
 * 	1 if s1 is earlier alphabetically than s1 
 * 	-1 if s2 is earlier alphabetically than s1 
 */ 
int safe_strcmp(safe_string *s1, safe_string *s2)
{ 
	if(s1->str != NULL && s2->str != NULL)
	{
		int done = 0; 
		int s1_ind = 0; 
		int s2_ind = 0;
		int s1_len = s1->allocated_length; 
		int s2_len = s2->allocated_length;
		int retval = 0; //assuming identical   
		while(s1_ind < s1_len && s2_ind < s2_len) 
		{ 
			if(s1->str[s1_ind] == s2->str[s2_ind]) 
			{
				s1_ind++;
				s2_ind++; 
			}
			else if(s1->str[s1_ind] > s2->str[s2_ind])
			{ 
				return -1; 
			} 
			else
			{
				return 1; 
			} 
		} 
		//strings are exactly the same in terms of chars comp. 
		// in while loop  
		if(s1_len < s2_len)
		{
			return -1; 
		} 
		else if(s2_len > s1_len)
		{ 
			return 1; 
		}
		else
		{
			return 0; 
		} 
	}
	else if(s1->str == NULL && s2->str != NULL) 
	{
		return 1;  
	} 
  	else if(s2->str == NULL && s1->str != NULL)
	{
		return -1; 
	}  
	else //s2->str == NULL && s1->str == NULL
	{
		return 0; 
	}  
} 
