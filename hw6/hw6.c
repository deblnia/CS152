#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw6.h"

char *category_strings[] = { "Grocery", "Office", "Pharmacy", "Hobby"};

void print_product(product_info *p, FILE *fp)
{
	fprintf(fp,"%s (%u) %s:\n",p->name, p->productID,
		category_strings[p->category]);
	fprintf(fp, "current: %u, min: %u, max: %u\n",
		p->current_stock, p->min_for_restock, p->max_after_restock);
}

void print_list(node *head, FILE *fp)
{
	node *tmp;
	printf("\nProduct Status:\n");
	for(tmp = head; tmp != NULL; tmp = tmp->next)
	{
		print_product(tmp->product,fp);
		printf("\n");
	}
}

/* product_info
 * allocates memory and fills in the fields for a product
 * inputs:
 *      char *name
 *      char *category
 *      uint id
 *      uint current
 *      uint mn
 *      uint mx
 * outputs:
 *      a pointer to newly allocated and initialized memory
 */
product_info *create_product(char *name, char *category, uint id,
				uint current, uint mn, uint mx)
{
     product_info *new_product;
     new_product = (product_info*)malloc(sizeof(product_info));

     strcpy(new_product->name,name);

     if(strcmp(category, category_strings[0]) == 0)
     {
         new_product->category = GROCERY;
     }
     else if(strcmp(category, category_strings[1]) == 0)
     {
         new_product->category = OFFICE;
     }
     else if(strcmp(category, category_strings[2]) == 0)
     {
         new_product->category = PHARMACY;
     }
     else if(strcmp(category, category_strings[3]) == 0)
     {
         new_product->category = HOBBY;
     }
     new_product->productID = id;
     new_product->current_stock = current;
     new_product->min_for_restock = mn;
     new_product->max_after_restock = mx;

     return new_product;

}

/* insert_head
 * adds a product to the "head" or beginning of a list
 * inputs:
 * 		node *head - pointer to head (beginning) of type node
 * 		product_info *pinfo - an object of type product info to put in the head
 * outputs:
 *      returns a pointer to the first node in the modified list
 */
node* insert_head(node *head, product_info *pinfo)
{
    node *new_head = NULL;
    new_head = (node*)malloc(sizeof(node));
    new_head->product = pinfo;
    new_head->next = head;
    return new_head;
}

/* find
 * finds record for the product
 * inputs:
 * 		node *head - pointer to head (beginning) of type node
 * 		uint pID - product id to return
 * outputs:
 *      returns a pointer to record containing pID
 */
 product_info *find(node *head, uint pID)
 {
     node *tmp = NULL;
     for(tmp=head;tmp != NULL; tmp = tmp->next)
     {
         if(tmp->product->productID == pID)
         {
             return tmp->product;
         }
     }
    return tmp->product;
 }

 /* record_restocked_single
  * Given productID, records single item as restocked (current
  * number of items as max number of items)
  * inputs:
  *    node *head
  *    uint pID
  * outputs:
  *    none. void
  */
 void record_restocked_single(node *head, uint pID)
 {
     product_info *found_product;
     found_product = find(head, pID);

     if(found_product != NULL)
     {
         found_product->current_stock = found_product->max_after_restock;
     }
 }

 /* product_sold
  * Given productID, finds the record for the product and decrements \
  * the number of items currently in stock for that item
  * inputs:
  *      node *head
  *      uint pID
  * outputs:
  *      none. void
  */
 void product_sold(node *head, uint pID)
 {
     product_info *found_product;
     found_product = find(head, pID);
     if(found_product != NULL)
     {
        uint current_stock = found_product->current_stock;
        if(current_stock > 0)
        {
            current_stock--;
            found_product->current_stock = current_stock;
        }
     }
 }

 /*add_sorted_productID
 * inserts immediately prior to the first product it finds with a larger
 * productID than it has. If there are no product with larger productIDs,
 * then it places it at the end of the list
 * returns a pointer to the beginning of the modified list. MOM!!!!
 */
node *add_sorted_productID(product_info *pinfo, node *head)
{
    node *curr = head;
    node *next = head;
    node *start = NULL;
    //Add node BEFORE the 1st node in the list
    if(curr != NULL && curr->product->productID >= pinfo->productID)
    {
        start = insert_head(head, pinfo);
        return start;
    }
    //Add node in the middle of the list
    for(curr=head;curr != NULL; curr = curr->next)
    {
           next = curr->next; //Look one node ahead to see if node needs to be added between curr and next
           if(next != NULL)
           {
               if(next->product->productID >= pinfo->productID)
               {
                   //insert in list
                   start = insert_head(next, pinfo); // inserted in between current and next nodes
                   print_list(start, stdout);
                   curr->next = start; //Make the current node point to the newly added node
                   return start;
               }
           }
    }
    //pinfo added to the end OR this is the start of a new list
    start = insert_head(curr,pinfo);
    if (curr) // if current node is not NULL, then make the last node point to the newly added node
        curr->next = start;
    return start;
}

/*add_sorted_category_ID
 * inserts immediately prior to the first product it finds with a larger
 * productID than it has within the same category.
 * If there are no product with larger productIDs,
 * then it places it at the end of the list
 * returns a pointer to the beginning of the modified list. MOM!!!!
 *
 */
node *add_sorted_category_ID(product_info *pinfo, node *head)
{
   node *iter = head;
   node *next = head;
   node *curr = head;
   node *start = NULL;
   //Add node BEFORE the 1st node in the list
   if(curr != NULL && \
       ((curr->product->productID >= pinfo->productID && curr->product->category == pinfo->category) || (curr->product->category > pinfo->category))) //curr cat > pinfo cat
   {
       start = insert_head(head, pinfo);
       return start;
   }
    //Add node in the middle of the list
   for(curr=head;curr!= NULL; curr=curr->next)
   {
        next = iter->next; //Look one node ahead to see if node needs to be added between curr and next
        if(next != NULL && \
            ((next->product->productID >= pinfo->productID && next->product->category == pinfo->category) || (next->product->category > pinfo->category))) //check for cat less
        {
                   //insert in list
                   start = insert_head(next, pinfo); // inserted in between current and next nodes
                   curr->next = start; //Make the current node point to the newly added node
                   return start;
        }
   }
   //pinfo added to the end OR this is the start of a new list
   start = insert_head(curr,pinfo);

   if (curr) // if current node is not NULL, then make the last node point to the newly added node
        curr->next = start; // if current node is not NULL, then make the last node point to the newly added node
   return start;
}

/* make_restock_list
 * creates a new linked list containing all the items
 * that need to be restocked.
 * inputs:
 *      node *head
 * ouputs:
 *      node pointer to head of new list
 */
node *make_restock_list(node *head)
{
    node *new_list = NULL;
    for(head; head != NULL; head = head->next)
    {
        if(head->product->current_stock < head->product->min_for_restock)
        {
            new_list = insert_head(new_list, head->product);
        }
    }
    return new_list;
}
/* record_restocked_list
 * changing values of current_stock in original list to
 * reflect restocking
 * inputs:
 *      node *restocked_list
 *      node *head
 * outputs:
 *      none. void
 */
void record_restocked_list(node *restocked_list, node *head)
{
    node *tmp = restocked_list;
    product_info *changed = NULL;
    for(tmp = restocked_list; tmp != NULL; tmp = tmp->next)
    {
        changed = find(head, tmp->product->productID);
        if(changed != NULL)
        {
            changed->current_stock = changed->max_after_restock;
        }
    }
}
