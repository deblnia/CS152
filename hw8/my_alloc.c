#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "memory.h"
#include "llist.h" 

/* Global variables
 * By declaring these outside of a function:
 *   Scope: Every function inside of this file may use them.
 *   		No functions in other files may use them.
 *   Lifetime: They exist for the entire program - they are created
 *		when the program begins and exist until the program
 *		ends.
 */

/* This is the tree that holds the available memory. */
bst *avail_mem = NULL;

/* This includes all of the functions for the memory allocator.
 * The last two functions (my_malloc and my_free) are public
 * functions with prototypes in the header function. The rest of the
 * functions are helper functions only called by my_malloc and
 * my_free. You must implement these helper functions. If you wish,
 * you may add helper functions we did not define.
 */

/* This function allocates a single page (4096 bytes) and creates the memory 
 * structure that points to it. The pointer ret_val will be returned. 
 */ 
//need to use memory function to initialize memory struct
memory *allocate_memory_page(){ //Wed
    memory  *ret_val = NULL; 
    void *allocated_mem_p = NULL;

    allocated_mem_p = (void*)malloc(4096); 
    *((int *)allocated_mem_p) = 4088;
    ret_val = memory_new (allocated_mem_p, 4088);    
    return ret_val; 
}

/* helper function to advance pointer by specified amount
 */ 
void* advance_by_x(void *v, int x)
{
	char *pc = (char*)v;
	pc += x; 
	return (void*)pc;
}

/* This function takes a memory* that has more than size_desired memory in it 
 * and splits it off into the chunk that can be passed to the program and the 
 * portion that is still able to be passed out later.
 */ 
void *split_memory(memory* data, unsigned int size_desired){
    
    memory_print(data); 
    int original_size = data->size; 
    if(size_desired > original_size)
        {
            printf("Desired size of %d is bigger than available size  of %d  unable to split memory.\n", size_desired, original_size); 
            return NULL;
        } 
    int size_of_big_jump = (8 + data->size); 
    printf("size of big jump - %d \n", size_of_big_jump);  
    int desired_loc = size_of_big_jump - size_desired; 
   
   void *ret_val = advance_by_x(data->addr, desired_loc); 
   // printf("after first advance_by, desired loc %d\n", desired_loc); 
    
    //putting allocated memory size in 8 bytes
    void *allocated_size; 
    int desired_location_size = desired_loc - 8; 
    allocated_size = advance_by_x(data->addr, desired_location_size);
    //printf("after second advance_by\n"); 
    //Wed ---- (int*)(allocated_size); //= size_desired; // seg fault is here
    *((int *)allocated_size) = size_desired; //add for address 

    //adjusting available memory in data 
    data->size = original_size - size_desired - 8; // Wed
    memory_print(data);
    return ret_val; 
}

/* compact_memory
 *
 * Search through all available memory and attempt to merge memory
 * that is stored next to each other.
 * This uses global variable avail_mem, so it does not need any
 * input parameters. Look at the bst functions and memory functions.
 */
void compact_memory()
{

    //Create a BST ordered by address (instead of size). Do this by : 
    //  - traversing avail_mem and creating a linked list
    //  - iterate through the linked list and bst_insert nodes to b_avail_mem_address 
    //    in ascending order of address
    bst *avail_mem_addr = NULL;
    
    avail_mem_addr=bst_new(memory_addr_cmp);
    bst_iterate_n_create_addr_bst(avail_mem, avail_mem_addr);
    printf("COMPACT MEMORY -- printing tree\n"); 
    bst_inorder_traversal(avail_mem, memory_print);     
    //Create a linked list of nodes from avail_mem_address
    // Traverse this list and check if 2 consecutive memory structs can be merged
    // If 2 nodes merge, then remove the merged node with higher address from avail_mem
    llist* tmp_list=NULL;
    /* If the tree is not NULL, traverse the BST*/
    if (avail_mem_addr != NULL) {
        tmp_list = create_llist();
        inorder_traversal_insert_llist(avail_mem_addr->root, tmp_list);
        //iterate tmp_list and add nodes to bst_addr in order of ascending address        
        void *curr_item = NULL;
        void *prev_item = NULL;
        for(curr_item = iterate(tmp_list); curr_item != NULL; curr_item = iterate(NULL)) {
            printf("COMPACT -- curr_item:\n");
            memory_print(curr_item);
            if (curr_item!= NULL && prev_item != NULL) {
                printf("COMPACT MEMORY - prev_item:\n"); 
                memory_print(prev_item); 
                if (merge_memory(curr_item, prev_item)) { 
                    bst_delete(avail_mem, curr_item);
                }
                else 
                    prev_item=curr_item;
            } 
            else
                prev_item = curr_item; 
        } 
    }
}

/* print_available_memory
 *
 * Print out all available memory in ascending order by size.
 */
//IS THE LINKED LIST ITERATOR BEING EXPECTED TO BE USED HERE??
void print_memory()
{
    printf("Printing heap:\n"); 
    bst_inorder_traversal(avail_mem, memory_print);
    printf("Done printing heap.\n"); 
}

/* init_alloc
 *
 * Initializes the data structures. This initializes avail_mem so
 * that, instead of being a NULL pointer, it points to a valid bst
 * struct whose root pointer is NULL.
 */
void init_alloc()
{
	static init_alloc_called = 0;
    if (init_alloc_called == 0) {
        avail_mem=bst_new(memory_size_cmp);
        init_alloc_called = 1;
    }
}

/* my_malloc
 *
 * function that finds a piece of available memory that is at least
 * num_bytes size. A pointer to the beginning of the usable piece of
 * that chunk is returned.
 */
void *my_malloc(int num_bytes)
{

    memory *memdata= NULL; 
    memory *mem_allocated=NULL;
    memory *ret_mem_ptr=NULL;
    int mem_allocated_size = 0;
    
    printf ("my_malloc start - num_bytes=%d\n", num_bytes);

    if (num_bytes < 24 || num_bytes > 4088) { //Sat
        printf("my_malloc- minimum requested memory size should be 24. max is 4088, requested size is %d\n", num_bytes);
        return NULL;
    }
    int remainder;
    //IF num_bytes is not a multiple of 8 then get the next lowest large multiple of 8 closest to num_bytes 
    if (num_bytes % 8 !=0) {
        num_bytes = ((num_bytes/8) + 1)*8;
        printf ("my_malloc - num_bytes was adjusted to (%d) to align by 8\n", num_bytes);
    }
    
    
    memdata = memory_new(1,num_bytes);
    
    mem_allocated= bst_item_or_successor(avail_mem, memdata);
    //bst_item_or_successor returns a pointer to a memory struct, 
    // so mem_allocated is a memory pointer 
    
    if (mem_allocated != NULL) {
        mem_allocated_size = mem_allocated->size;
        printf ("my_malloc - found memory chunk in avail_mem, size of avail chunk %d\n", mem_allocated_size);
        //Split the memory from the end if avail_mem chunk size is >= 2 * num_bytes
        if (mem_allocated_size >= (num_bytes * 2)) {
            printf ("my_malloc - going to return num_bytes(%d) of space by splitting avail mem chunk\n", num_bytes);
            ret_mem_ptr=split_memory(mem_allocated, num_bytes);
            //Reinsert the remaining avail mem int he correct position in BST by deleting/inserting
            bst_delete(avail_mem, mem_allocated); //node is NOT freed in BST
            bst_insert(avail_mem, mem_allocated); //mem allocated has new smaller size
        }
        else { // if avail mem chunk size < 2*num_bytes then give out entire chunk - no need to split
             printf ("my_malloc - going to return entire avail chunk(%d) of space\n", mem_allocated_size);
            ret_mem_ptr = mem_allocated;
            //remove this node from BST as it's no longer available
            bst_delete(avail_mem, mem_allocated); //node is NOT freed in BST
        }
    }
    //need to get a new page of memory as there is no available chunk in avail_mem
    else {
        printf ("my_malloc - allocating new page of memory");
        mem_allocated=allocate_memory_page();
        ret_mem_ptr=split_memory(mem_allocated, num_bytes);
            //Reinsert the remaining avail mem int he correct position in BST by deleting/inserting
       //printf("hello from 179\n"); 
        bst_insert(avail_mem, mem_allocated);
       printf("hello after bst insert\n");
       // printf("ret_mem_ptr = %p\n"); 
     print_memory(); 
    printf("IN MY_MALLOC PRINTING AFTER ALLOCATING NEW PAGE\n"); 
    bst_inorder_traversal(avail_mem, memory_print);  
    }
    
    //Need to return ptr to allocated space for num_bytes or more
	return ret_mem_ptr;


}

/* my_free
 *
 * Function that returns the memory chunk whose usable piece starts
 * at that address back to the set of available memory so that it can
 * be reused in a subsequent free call
 */
void my_free(void *address)
{
    char *pc = NULL;
    memory *mem_data=NULL;
    int num_bytes = 0; 
    printf ("my_free, address ptr %p\n", address);
	if (address != NULL) {
        //Get beginning of address -- first 8 bytes have size in it so move ptr back by 8
        pc = (char*)address;
	    pc = pc - 8; 

        num_bytes = *((int*)(pc));
        printf("my_free - num bytes - %d\n", num_bytes); 
        
        mem_data = memory_new(((void*)pc),num_bytes);
    
        //Insert into avail_mem
        bst_insert(avail_mem, mem_data);
    }

}
