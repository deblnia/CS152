#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw6.h"

int main(int argc, char *argv[])
{
	// make sure there are two arguments - hw5 and filename
	if (argc < 2)
	{
		printf("Usage: ./hw6 filename. Missing filename\n");
		exit(1);
	}
	char *filename = argv[1];

	// open file for reading
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Could not open file %s for reading\n",filename);
		exit(2);
	}

	// read in each record from the file
	char buffer[BUFSIZ];
	node *product_list = NULL;
	while (!feof(fp) && (fgets(buffer,500,fp) != NULL))
	{
		// parse the line to split up the fields
		char *category;
		char *name;
		uint pID;
		uint current_stock;
		uint min_stock;
		uint max_stock;
		char *tmp_s;

		// first field is category
		category = strtok(buffer," ,\n\r");
		// second field is name
		name = strtok(NULL," ,\n\r");
		// third is pID;
		tmp_s = strtok(NULL," ,\n\r");
		pID = atoi(tmp_s);
		// fourth is current
		tmp_s = strtok(NULL," ,\n\r");
		current_stock = atoi(tmp_s);
		// fifth is min
		tmp_s = strtok(NULL," ,\n\r");
		min_stock = atoi(tmp_s);
		// sixth is max
		tmp_s = strtok(NULL," ,\n\r");
		max_stock = atoi(tmp_s);

		printf("Read in record: %s, %s, %u, %u, %u, %u\n",
			category, name, pID, current_stock, min_stock,
			max_stock);

		// now you need to write the code to create a record
		// and put that record into the linked list
		product_info *new_product;
		new_product = create_product(name, category, pID, current_stock,
											min_stock, max_stock);
		print_product(new_product, stdout);
		product_list = insert_head(product_list, new_product);
		print_list(product_list, stdout);

	}
// here you can add stuff to test your other functions
printf("TESTING FIND:\n");
product_info *find_one = find(product_list, 23765);
if(find_one != NULL)
{
	printf("find_one - %s\n", find_one->name);
}
else
	printf("not found 1 \n");
product_info *find_two = find(product_list, 92656);
if(find_two != NULL)
	printf("find_two - %s\n", find_two->name);
else
	printf("Not found 2\n");
product_info *find_three = find(product_list, 38590);
if(find_three != NULL)
	printf("find_three - %s\n", find_three->name);
else
	printf("not found 3\n");

printf("\nTESTING RECORD RESTOCK SINGLE:\n");
record_restocked_single(product_list, 3826);
record_restocked_single(product_list, 92656);
record_restocked_single(product_list, 8261);
print_list(product_list, stdout);



printf("\nTESTING PRODUCT SOLD:\n");
product_sold(product_list, 3826);
product_sold(product_list, 92656);
product_sold(product_list, 8261);
print_list(product_list, stdout);


printf("\nTESTING ADD SORTED PRODUCT ID:\n");
node *sorted_one = NULL;
product_info *prod_info = create_product("Flower", "Grocery", 92655, 10, 5,20);
sorted_one = add_sorted_productID(prod_info, product_list);
print_list(sorted_one, stdout);

node *sorted_two = NULL;
product_info *prod_info2 = create_product("PaperClip", "Pharmacy", 380570 , 10, 5,20);
sorted_two = add_sorted_productID(prod_info2, product_list);
print_list(sorted_two, stdout);

node *sorted_three = NULL;
product_info *prod_info3 = create_product("Huge", "Pharmacy", 100000000 , 10, 5,20);
sorted_three = add_sorted_productID(prod_info3, product_list);
print_list(sorted_three, stdout);


printf("\nTESTING ADD SORTED CATEGORY ID:\n");
node *cat_one = NULL;
product_info *cat_test = create_product("Flower", "Grocery", 92655, 10, 5,20);
cat_one = add_sorted_category_ID(cat_test, product_list);
print_list(cat_one, stdout);

node *cat_two = NULL;
product_info *cat_2 = create_product("Muji", "Office", 23766 , 10, 5,20);
cat_two = add_sorted_category_ID(cat_2, product_list);
print_list(cat_two, stdout);

node *cat_three = NULL;
product_info *cat_3 = create_product("Something", "Hobby", 380752 , 10, 5,20);
cat_three = add_sorted_category_ID(cat_3, product_list);
print_list(cat_three, stdout);

printf("\nTESTING MAKE RESTOCK LIST:\n");
product_sold(product_list, 3826);
product_sold(product_list, 3826);
product_sold(product_list, 3826);
product_sold(product_list, 3826);
product_sold(product_list, 3826);
product_sold(product_list, 3826);
product_sold(product_list, 3826);
product_sold(product_list, 3826);
product_sold(product_list, 3826);
node *restock_list_test = make_restock_list(product_list);
print_list(restock_list_test, stdout);

printf("\nTESTING RECORD RESTOCK LIST:\n");
record_restocked_list(restock_list_test, product_list);
print_list(product_list, stdout);


}
