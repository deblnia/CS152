#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
#include "llist.h"
#include "memory.h" 

/* malloc a new node and assign the data
 * pointer to its data field
 */
node* node_new(void* data){
  node *new_node = NULL;
  new_node = (node*)malloc(sizeof(node)); //changed new_mode to new_node
  new_node->data = data;
  new_node->left=NULL; 
  new_node->right=NULL;
  return new_node;
}

/* create a new bst, initialize its root to be NULL
 */
bst* bst_new(int (*cmp)(const void* x, const void* y)){
  bst *new_bst = NULL;
  new_bst = (bst*)malloc(sizeof(bst));
  new_bst->root = NULL;
  new_bst->cmp = cmp;

  return new_bst;
}

/* Insert a node to to a subtree with a root node as parameter
 * Insertion is in sorted order.
 * Return the new root of the modified subtree.
 */
node* node_insert(node* root, void* data,
    int (*cmp)(const void* x, const void* y)){
    
    //Correct leaf node position found
    if (root == NULL) {
        return(node_new(data));
    }

    //Root is not null, not reached a leaf node, so continue traversing to find location
    int result = 0;
    result = cmp(data, root->data);
    if(result == -1) //data is less than root, traverse left subtree
        root->left= node_insert(root->left, data, cmp);
    else if(result == 0) //If the data is the same as root, then replace root with data
        root->data = data;
    else if(result == 1) //data is greater than root, traverse right subtree
        root->right= node_insert(root->right, data, cmp);
    /* return the (unchanged) node pointer */
    return root;
}

/* Insert a new node to the bst
 * Insert a new node to the bst. Note that our bst has a field of comparison function, so you 
 * need to use that comparison function to insert a node.
 */
void bst_insert(bst* b, void* data){
    /* If the tree is not NULL, insert the new node*/
    if (b != NULL) {
        b->root = node_insert(b->root, data, b->cmp);
    }
    else
       printf ("bst_insert - Binary search tree needs to be initialized first!\n");
}

/* delete a node from a subtree with a given root node
 * use the comparison function to search the node and delete
 * it when a matching node is found. This function only
 * deletes the first occurrence of the node, i.e, if multiple
 * nodes contain the data we are looking for, only the first node
 * we found is deleted.
 * Return the new root node after deletion.
 */
node* node_delete(node* root, void* data,
    int (*cmp)(const void* x, const void* y)){
    
    //Base case
     if (root == NULL) 
        return root;
  
    int result = 0;
    result = cmp(data, root->data);
 
    //if data is smaller than root, then traverse left subtree
    if(result == -1)
    {
        root->left = node_delete(root->left, data, cmp);
    }
    //if data is greater than root, then traverse right subtree
    else if(result == 1)
    {
        root->right = node_delete(root->right, data, cmp);
    }
    //found node to delete since result is 0
    else
    {
      // node with only one child or no child, return a pointer to the child node or NULL
        if (root->left == NULL)
        {
            node *temp = root->right;
            //free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            //free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest in the right subtree)
        node *temp = root->right;
        while(temp && temp->left != NULL)
            temp = temp->left;
        return temp;

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = node_delete(root->right, temp->data, cmp);
    }
    return root;
}

/* delete a node containing data from the bst
 */
void bst_delete(bst* b, void* data){
    /* If the tree is not NULL, insert the new node*/
    if (b != NULL) {
        node_delete(b->root, data, b->cmp);
    }
    else
       printf ("bst_delete - Binary search tree has not been initialized!\n");
}

/* Search for a node containing data in a subtree with
 * a given root node. Use recursion to search that node.
 * Return the first occurrence of node.
 */
void* node_search(node* root, void* data,
    int (*cmp)(const void* x, const void* y)){
    
    // Base Case: root is null 
    if (root == NULL) {
        printf ("node_search - Data NOT FOUND in BST\n");
        printf ("   Data -- "); 
        memory_print(data);  
        return 1;
    }

     int result = cmp(data, root->data);
    // data is less than root, traverse left subtree
    if (result == -1) 
    { 
        node_search(root->left, data, cmp);
    } 
    else if(result == 0) 
    { //If the data is the same as root, then done
        printf ("node_search - Found data in BST\n");
        printf ("   Data -- "); 
        memory_print(data);
        printf ("   BST  -- "); 
        memory_print(root->data);
        printf ("\n");
        return 1;
    }
    else if(result == 1) //data is greater than root, traverse right subtree
        node_search(root->right, data, cmp);
}

/* Search a node with data in a bst.
 */
void* bst_search(bst* b, void* data){
    /* If the tree is not NULL, insert the new node*/
    if (b != NULL) {
        node_search(b->root, data, b->cmp);
    }
    else
       printf ("bst_search - Binary search tree has not been initialized!\n");
}

/* traverse a subtree with root in ascending order.
 * Apply func to the data of each node.
 */
void inorder_traversal(node* root, void(*func)(void* data)){
    //printf ("inorder_traveral- start\n");
  if (root != NULL) {
      inorder_traversal(root->left, func); //recurse on left node
      func(root->data); //print the root data
      inorder_traversal(root->right,func); //recurse on right node
  }
      //printf ("inorder_traveral- end\n");
}

/* traverse a bst in ascending order.
 * Apply func to the data of each node.
 */
void bst_inorder_traversal(bst* b, void(*func)(void* data)){

        /* If the tree is not NULL, traverse the BST*/
    if (b != NULL) {
        inorder_traversal(b->root, func);
    }
    else
       printf ("bst_inorder_traversal - Binary search tree has not been initialized!\n");
}

// a helper function to create linked list from bst by in order traversal 
void inorder_traversal_insert_llist(node* root, llist* l){     
    //printf("inorder_traversal_insert_llist- start\n");  
    if (root != NULL) {
        inorder_traversal_insert_llist(root->left, l); //recurse on left node
        insert_tail(l, root->data); //insert to linked list
        inorder_traversal_insert_llist(root->right, l); //recurse on right node   }
    //printf ("inorder_traversal_insert_llist- end\n");
    }   
}


/* an iterator to iterate through the bst in ascending order
 */
void* bst_iterate(bst* b){
    
    static llist* bst_list=NULL;
    /* If the tree is not NULL, traverse the BST*/
    if (bst_list != NULL) {
        bst_list = create_llist();
        inorder_traversal_insert_llist(b->root, bst_list);
        //iterate and print the linked list         
        iterate(bst_list); 
    }
    else
    {
            iterate(NULL);
    }
}

/* free the node subtree structure                              
 */                                                             
void node_free(node* root){                                     
                                                                
    if (root == NULL) return;                                   
                                                                
    /* first free both subtrees */                              
    node_free(root->left);                                      
    node_free(root->right);                                     
                                                                
    /* then free the root */                                    
    free(root);                                                 
}                                                               

/* an iterator to iterate through the bst in ascending order and i
 * add nodes to 2nd bst_addr - 
 *    ordering nodes in ascending address order
 */
void* bst_iterate_n_create_addr_bst(bst* b, bst* bst_addr){
    
    llist* tmp_list=NULL;
    /* If the tree is not NULL, traverse the BST */
    if (b != NULL) {
        tmp_list = create_llist();
        inorder_traversal_insert_llist(b->root, tmp_list);
        //iterate tmp_list and add nodes to bst_addr in order of ascending address        
        void *item;
        for(item = iterate(tmp_list); item != NULL; item = iterate(NULL))
	    {
            bst_insert(bst_addr, item);
        } 
    }
    else 
        printf ("bst_iterate_n_create_addr_bst - BST is not initialized, nothing to do!\n"); 
}

/* free the bst with                                            
 */                                                             
void bst_free(bst* b){                                          
                                                                
 if (b == NULL) return;                                         
 node_free(b->root);                                            
}                  

/*****************************
 *    HOMEWORK 7
 *****************************/
/*
 * item_or_successor
 *
 * find an item that is equal or, if there isn't one that is
 * equal, find the one that is next larger to the requested
 * item.
 *
 * The purpose of this function is that, given a size of a
 * chunk of memory desired, it attempts to find an available
 * chunk of memory the same size. If there is no chunk of
 * memory the same size, it finds the chunk of memory that is
 * closest to that size but larger.
 *
 * It returns a pointer to the memory struct. The compare
 * function in the bst is the one that performs the comparisons.
 */
void* node_item_or_successor(node *n, void *item,
        int (*cmp)(const void* x, const void* y)){
        
    node *root = n;
    node *succ = NULL;
    printf ("node_item_or_successor - item to search ");
    memory_print(item);

    if (root == NULL) {
        printf ("node_item_or_successor - NODE is NULL - nothing to search!\n");
        return NULL;
    }

    int result = 0;
    while (root != NULL)
    {
       // printf("HELLO FROM WHILE\n"); 
        result = cmp(item, root->data);
        printf("printing result from node_inorder_suc - %d\n", result); 

        //if item size is smaller than root, traverse left subtree; keep track of the last root node larger than item
        if(result == -1) {
           // printf("hello from -1\n"); 
            succ = root;
            root = root->left;
           // printf("from node_in_order_suc: successor %p, root %p\n", succ,
            //root); 
        }
        //if item is greater than root, then traverse right subtree; no need to keep track of nodes of trees as none of these nodes have sufficient space to split off
        else if(result == 1)
        {
            printf("hello from result 1\n"); 
            root = root->right;
        } 
        else { //result == 0 item size is same as node, then return this node
            printf ("node_item_or_successor - found a node of same size in BST, printing node -- ");
            memory_print(root->data);
            return (root->data);
        }

    }
   // printf("hello from line 308\n");
   // printf("success pointer - %p\n", succ); 
    //memory_print(succ->data); 
    if(succ != NULL) {
        printf ("node_item_or_successor - found a node of LARGER size in BST, printing node -- ");
        memory_print(succ->data);
        return (succ->data);
    }
    return succ; //if succ is NULL
} 
void* bst_item_or_successor(bst *b, void *item){
    void* data_ptr = NULL;
    /* If the tree is not NULL, traverse the BST to find the inorder successor of item */
    if (b != NULL) {
        data_ptr=node_item_or_successor(b->root, item, b->cmp);
    }
    else
       printf ("bst_item_or_successor- Binary search tree has not been initialized!\n");
    return data_ptr;
} 
