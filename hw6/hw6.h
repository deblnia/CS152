#ifndef HW6_H
#define HW6_H

typedef unsigned int uint;

enum Category { GROCERY=0, OFFICE, PHARMACY, HOBBY};
#define NUM_CATEGORIES 4

typedef struct {
 enum Category category;
 char name[40];
 uint productID;
 uint current_stock;
 uint min_for_restock;
 uint max_after_restock;
} product_info;

// for the linked list, we will use the following struct
typedef struct _node node;

struct _node{
 product_info *product;
 node *next;
};

extern char *category_strings[];
void print_product(product_info *g, FILE *fp);
void print_list(node *head, FILE *fp);

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
 				uint current, uint mn, uint mx);

/* insert_head
* adds a product to the "head" or beginning of a list
* inputs:
* 		node *head - pointer to head (beginning) of type node
* 		product_info *pinfo - an object of type product info to put in the head
* outputs:
*      returns a pointer to the first node in the modified list
*/
node* insert_head(node *head, product_info *pinfo);

/* find
 * finds record for the product
 * inputs:
 * 		node *head - pointer to head (beginning) of type node
 * 		uint pID - product id to return
 * outputs:
 *      returns a pointer to record containing pID
 */
 product_info *find(node *head, uint pID);

/* record_restocked_single
 * Given productID, records single item as restocked (current
 * number of items as max number of items)
 * inputs:
 *    node *head
 *    uint pID
 * outputs:
 *    none. void
 */
void record_restocked_single(node *head, uint pID);

/* product_sold
 * Given productID, finds the record for the product and decrements \
 * the number of items currently in stock for that item
 * inputs:
 *      node *head
 *      uint pID
 * outputs:
 *      none. void
 */
void product_sold(node *head, uint pID);



/*add_sorted_productID
 * inserts immediately prior to the first product it finds with a larger
 * productID than it has. If there are no product with larger productIDs,
 * then it places it at the end of the list
 */
node *add_sorted_productID(product_info *pinfo, node *head);

/*add_sorted_category_ID
 * inserts immediately prior to the first product it finds with a larger
 * productID than it has within the same category.
 * If there are no product with larger productIDs,
 * then it places it at the end of the list
 * returns a pointer to the beginning of the modified list. MOM!!!!
 *
 */
node *add_sorted_category_ID(product_info *pinfo, node *head);

/* make_restock_list
 * creates a new linked list containing all the items
 * that need to be restocked.
 * inputs:
 *      node *head
 * ouputs:
 *      node pointer to head of new list
 */
node *make_restock_list(node *head);

/* record_restocked_list
 * changing values of current_stock in original list to
 * reflect restocking
 * inputs:
 *      node *restocked_list
 *      node *head
 * outputs:
 *      none. void
 */
void record_restocked_list(node *restocked_list, node *head);


#endif
