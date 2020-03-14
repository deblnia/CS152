#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "memory.h"
#include "my_alloc.h"
#include "llist.h"

extern bst* avail_mem; 

int main(int argc, char *argv[])
{


//part I, problem 1  
printf("PART I: PROBLEM 1\n"); 

printf("Starting allocate_memory_page\n"); 
memory *page = allocate_memory_page(); 
printf("MAIN -- "); 
memory_print(page); 
printf("\n\n"); 


printf("Splitting 128 memory\n");
memory *new_page = split_memory(page,128);
printf("MAIN -- "); 
memory_print(page); 
printf("\n\n"); 

printf("Splitting 256 memory\n"); 
memory *newer_page = split_memory(page, 256);
printf("MAIN -- "); 
memory_print(page); 
printf("\n\n"); 

printf("Splitting 4830 memory\n"); 
memory *newest_page = split_memory(page, 4830);
printf("MAIN -- "); 
memory_print(page); 
printf("\n\n"); 


//part I, problem 3  
printf("\n\n\n\nPART I: PROBLEM 3\n"); 


init_alloc(); //creates the avail mem bst with NULL (no avail mem) 

void *first_test = my_malloc(5); //shouldn't work 

printf("MAIN -- ALLOCATING 128\n"); 
void *second_test = my_malloc(128);
printf("\n MAIN -- Allocated 128 bytes.\n"); 
print_memory(); 
printf("\n\n"); 

printf("MAIN -- ALLOCATING 256\n"); 
void *third_test = my_malloc(256); 
printf("MAIN -- Allocated 256 bytes.\n"); 
print_memory(); 
printf("\n\n"); 

printf("MAIN -- ALLOCATING 3800\n"); 
memory *fourth_test = my_malloc(3800); 
printf("Allocated 3800 bytes."); 
print_memory(); 
printf("\n\n"); 

my_free(second_test);
printf("MAIN -- free 128.\n"); 
print_memory(); 
printf("\n\n"); 


my_free(third_test);
printf("MAIN -- free 256.\n"); 
print_memory(); 
printf("\n\n"); 

/*
my_free(fourth_test);
printf("MAIN -- free 3800.\n"); 
print_memory(); 
printf("\n\n"); 
*/ 


//part I, problem 2 
printf("\n\n\n\nPART II: PROBLEM 1\n"); 
printf("MAIN -- merginging memory test:\n"); 
memory *check_test = merge_memory(second_test, third_test); 


//bst* test1 = NULL; 
//bst_iterate(test1);

printf("MAIN -- time to compact memory\n"); 
compact_memory(); 
printf("MAIN -- done compacting. Printing heap.\n"); 
print_memory(); 


}
