#include<stdio.h>
#include<stdlib.h>
#include "memory.h"
#include "bst.h"


// void read_file_setup_memory_data(char *filename)
// {
//   FILE *fp;
//   char buf[BUFSIZ] = "Garbage";
//   int i;
//   char *tokenPtr;
//
//   // attempt to open the file, then check whether that worked.
//   if ((fp = fopen(filename, "r")) == NULL)
//   {
//     fprintf(stderr,"Could not open file %s\n",filename);
//   }
//
//   // for each line of the file, read it in and then print it out
//   i = 0;
//   while (fgets(buf, sizeof(buf), fp) != NULL)
//   {
//     printf ("Line %4d: %s", i, buf);
//     i++;
//
//     // initialize the string tokenizer and receive pointer to first token
//     tokenPtr = strtok(buf, ",");
//     while(tokenPtr != NULL) {
// 	   printf("Token -- %s\n",tokenPtr);
// 	   tokenPtr = strtok(NULL, ",");
//     }
//   }
//
//   fclose(fp);
// }

bst* read_memory_blocks(char *filename,
  int (*cmp)(const void* x, const void* y)){

    bst *file_bst=NULL;
    memory *memdata= NULL;
    file_bst=bst_new(cmp);
    // open file for reading
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
         	printf("Could not open file %s for reading\n",filename);
         	exit(2);
    }

    // read in each record from the file
    char buffer[BUFSIZ];
    while (!feof(fp) && (fgets(buffer,145,fp) != NULL))
    {
         	// parse the line to split up the fields
         	unsigned int  size;
         	unsigned int  address;
          	char *tmp_s;

         	// first field is size
         	  tmp_s = strtok(buffer,",");
            size = atoi(tmp_s);
            // second field is address
         	  tmp_s = strtok(NULL,",");
            address = atoi(tmp_s);

          //Insert data to BST and print
          memdata = memory_new(size,address);
         	printf("Read in from file: %u, %u\n", size, address);
          printf("Inserted into memdata: ");
          memory_print(memdata);
          printf("\n");
          bst_insert(file_bst, memdata);
    }
  printf("Starting in order traversal from read_memory_blocks:");
  bst_inorder_traversal(file_bst, memory_print);
  return file_bst;

}
