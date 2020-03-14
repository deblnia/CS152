#include<stdio.h>
#include<stdlib.h>
#include "memory.h"

/* memory_new
 * create a new memory struct, initialze its address and size
 */
memory* memory_new(void *addr, unsigned int size){
  memory* m = (memory*)malloc(sizeof(memory));
  m->addr = addr;
  m->size = size;
  return m;
}

/* free the dynamically allocated memory struct
 */
void memory_free(void* p){
  memory* m = (memory*)p;
  free(m);
}

/* This function takes two arguments, const void* x and const void* y,
 * you will need to cast both of them to type "memory*", and make comparisons.
 * If x is less than y, return -1. If x is greater than y, return 1. If they 
 * are equal, return 0;compare two memory variables x and y by address
 * if x is less than y, return -1
 * if x is greater than y, return 1
 * if they are equal, return 0
 */
int memory_addr_cmp(const void* x, const void* y){
  memory *temp_x = (memory*)(x);
  memory *temp_y = (memory*)(y);
  if(temp_x->addr < temp_y->addr) //there may be a problem w void* comp 
  {
    return -1;
  }
  else if(temp_x->addr > temp_y->addr)
  {
    return 1;
  }
  else if(temp_x->addr == temp_y->addr)
  {
    return 0;
  }
}

/* compare two memory variables x and y by size
 * if x is less than y, return -1
 * if x is greater than y, return 1
 * if they are equal, return 0
 */
int memory_size_cmp(const void* x, const void* y){
  memory *temp_x = (memory*)(x);
  memory *temp_y = (memory*)(y);
  if(temp_x->size < temp_y->size)
  {
    return -1;
  }
  else if(temp_x->size > temp_y->size)
  {
    return 1;
  }
  else if(temp_x->size == temp_y->size)
  {
    return 0;
  }
}

/* print the memory address and size
 */
void memory_print(void* data){
  if (data == NULL) return;
  memory* m = (memory*)data;
  printf("address: %p, size: %u\n", m->addr, m->size); //MOM - Wed
}

/* a merge function that attempts to merge two items. 
 * Given two memory structs, check to see if the two can 
 * be merged. They can be merged if the two are next to 
 * each other in memory with no break in between. If they 
 * can be merged, return a memory struct pointer to a 
 * struct containing the information for a single memory 
 * chunk containing the old two chunks. 
 * Free any memory structs that are no longer being used. 
 * If tey cannot be merged (there is space between them), 
 * then return NULL;
*/ 
memory* merge_memory(memory* x, memory* y){ 

    if (x == NULL || y == NULL || x->addr == NULL | y->addr == NULL)
    {
        printf("merge_memory -- memory struct or address is null\n"); 
        return NULL; 
    }    

    memory *low_mem = x; 
    memory *high_mem = y; 

    if (x->addr > y->addr)
    {
        low_mem = y; 
        high_mem = x; 
    }   

    char *pc = (char*)low_mem->addr;
    pc += (low_mem->size + 8);    
    printf("merge_memory - low_address %p, high address %p, low_address->size: %d\n", low_mem->addr, high_mem->addr, low_mem->size); 
   
    //figuring out if they are next to each other (else NULL) 
    if(((void *)pc) == high_mem->addr)
    {    
        printf("merge_memory -- can merge addresses. high_mem->addr = %p,  low_mem->addr = %p pc = %p\n", high_mem->addr, low_mem->addr,pc); 
        low_mem->size = x->size + y->size + 8; 
        printf("merge_memory -- final mem_size = %d\n", low_mem->size); 
        //free(*high_mem);
        //high_mem = NULL; 
        return low_mem; 
    } 
    else
    {
        printf("merge_memory. could not merge high_mem->addr = %p, low_mem->addr, pc = %p \n", high_mem->addr, low_mem->addr, pc); 
        return NULL;
    } 
}
