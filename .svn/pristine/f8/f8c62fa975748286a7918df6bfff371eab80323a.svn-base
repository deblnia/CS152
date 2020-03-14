#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "memory.h"
#include "hw7.h"
#define BUFSIZ 120

int main(int argc, char *argv[])
{
    //setup memdata for BST
    memory *memdata1 = NULL;
    memory *memdata2 = NULL;
    memory *memdata3 = NULL;
    memory *memdata4 = NULL;
    memory *memdata5 = NULL;
    memory *memdata6= NULL;
    memdata1 = memory_new(1,200);
    memdata2 = memory_new(2,50);
    memdata3 = memory_new(3,80);
    memdata4 = memory_new(4,100);
    memdata5 = memory_new(5,150);
    //To be used for searching
    memdata6 = memory_new(5,300);
    //print memory
    printf ("Printing initialized memory data\n");
    memory_print(memdata1);
    memory_print(memdata2);
    memory_print(memdata3);
    memory_print(memdata4);
    memory_print(memdata5);
    memory_print(memdata6);

    //Initialize BST -- sort data based on size
    bst *memsize_bst=NULL;
    memsize_bst=bst_new (memory_size_cmp);
    //Insert data to BST and print
    bst_insert(memsize_bst, memdata1);
    bst_insert(memsize_bst, memdata2);
    bst_insert(memsize_bst, memdata3);
    bst_insert(memsize_bst, memdata4);
    bst_insert(memsize_bst, memdata5);

		//Testing traversal
    printf ("Printing in order traversal of BST\n");
    bst_inorder_traversal(memsize_bst, memory_print);

    //Testing Search
    printf ("Searching BST for ");
		memory_print(memdata4);
    printf("\n");
    bst_search(memsize_bst, memdata4);

    printf ("Searching BST for ");
		memory_print(memdata2);
    printf("\n");
    bst_search(memsize_bst, memdata2);

		//Testing Delete
		printf("\nDeleting node ");
		memory_print(memdata3);
		printf("\n");
		bst_delete(memsize_bst, memdata3);


	 //Initialize BST -- sort data based on address
   bst *memaddr_bst=NULL;
   memaddr_bst=bst_new(memory_addr_cmp);
	 //Insert data to BST and print
	 bst_insert(memaddr_bst, memdata1);
	 bst_insert(memaddr_bst, memdata2);
	 bst_insert(memaddr_bst, memdata3);
	 bst_insert(memaddr_bst, memdata4);
	 bst_insert(memaddr_bst, memdata5);

	 //Testing traversal
	 printf ("Printing in order traversal of BST\n");
	 bst_inorder_traversal(memaddr_bst, memory_print);

	 //Testing Search
	 printf ("Searching BST for ");
	 memory_print(memdata4);
	 printf("\n");
	 bst_search(memaddr_bst, memdata4);

	 printf ("Searching BST for ");
	 memory_print(memdata2);
	 printf("\n");
	 bst_search(memaddr_bst, memdata2);

	 //Testing Delete
	 printf("\nDeleting node ");
	 memory_print(memdata3);
	 printf("\n");
	 bst_delete(memaddr_bst, memdata3);

	 //Testing memory blocks
	 bst *file_bst=NULL;
	 file_bst=read_memory_blocks("memory.txt", memory_size_cmp);

}
