#ifndef HW5_H
#define HW5_H 

typedef unsigned int uint;

typedef struct {
	char *str;
	uint allocated_length;
} safe_string;

/* make_empty_string
 * output: 
 * 	returns empty string initialized with NULL string and length 0 
 */
safe_string* make_empty_string();


/* make_string
 * makes safe string 
 * inputs: 
 * 	char *str - character pointer to string 
 * outputs: 
 * 	safe_string* - pointer to safe_string type 
 */ 
safe_string* make_string(char *str);

/* safe_str_cpy
 * safely copy string 
 * inputs: 
 * 	safe_string *dest - pointer to destination 
 * 	safe_string *src - pointer to source 
 * outputs: 
 * 	none. void
 */ 
void safe_str_cpy(safe_string *dest, safe_string *src);


/* safe_str_cat 
 * safely copy string 
 * inputs: 
 * 	safe_string *dest - pointer to destination 
 * 	safe_string *src - pointer to source 
 * outputs: 
 * 	none. void
 */ 
void safe_str_cat(safe_string *dest, safe_string *src);

/* *safe_strchr
 * safe_strchr returns a pointer that points within the string that s holds
 * inputs: 
 * 	safe_string *s - pointer to safe_string s 
 * 	char c - character to find 
 * outputs: 
 * 	index of first instance of character  
 */

char *safe_strchr(safe_string *s, char c);


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
int safe_strcmp(safe_string *s1, safe_string *s2);


#endif 
