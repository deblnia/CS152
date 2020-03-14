#include <stdio.h> 
#include <stdlib.h> 
#include "hw4_provided.h" 
#include "hw4.h" 


double surface_area_cylinder(double height, double radius)
{
	return 0.0;
}
/*hide_image
 * 
 */ 
void hide_image(
	unsigned int ref_r[ROWS][COLS], 
	unsigned int ref_g[ROWS][COLS], 
	unsigned int ref_b[ROWS][COLS], 
	unsigned int hid_r[ROWS][COLS], 
	unsigned int hid_g[ROWS][COLS], 
	unsigned int hid_b[ROWS][COLS], 
	unsigned int res_r[ROWS][COLS], 
	unsigned int res_g[ROWS][COLS], 
	unsigned int res_b[ROWS][COLS], 
	unsigned int height, unsigned int width)
{
int row; 
int col; 
for(row = 0; row < height; row++){
	for(col = 0; col < width; col++){
		if(hid_r[row][col] >= 128 && ref_r[row][col] %  2 == 1)
		{ 
			res_r[row][col] == ref_r[row][col] + 1; 
		} 
		else if(hid_r[row][col] < 128 && ref_r[row][col] %  2 == 0)
		{ 
			res_r[row][col] == ref_r[row][col] - 1;
 		}
		else
		{
			res_r[row][col] == ref_r[row][col]; 
		} 

		if(hid_b[row][col] >= 128 && ref_b[row][col] %  2 == 1)
		{ 
			res_b[row][col] == ref_b[row][col] + 1; 
		}
		else if(hid_b[row][col] < 128 && ref_b[row][col] %  2 == 0)
		{ 
			res_b[row][col] == ref_b[row][col] - 1;
 		}
		else
		{
			res_b[row][col] == ref_b[row][col]; 
		}
	 
		if(hid_g[row][col] >= 128 && ref_g[row][col] %  2 == 1)
		{ 
			res_g[row][col] == ref_g[row][col] + 1; 
		}
		else if(hid_g[row][col] < 128 && ref_g[row][col] %  2 == 0)
		{ 
			res_g[row][col] == ref_g[row][col] - 1;
 		}
		else
		{
			res_r[row][col] == ref_g[row][col]; 
		} 
	}
}

}

void extract_image(
	unsigned int res_r[ROWS][COLS], 
	unsigned int res_g[ROWS][COLS], 
	unsigned int res_b[ROWS][COLS], 
	unsigned int hid_r[ROWS][COLS], 
	unsigned int hid_g[ROWS][COLS], 
	unsigned int hid_b[ROWS][COLS], 
	unsigned int height, unsigned int width)
{
	int row; 
	int col; 
	for(row = 0; row < height; row++){
		for(col = 0; col < width; col++){
			if(res_r[row][col] %  2 == 1)
			{	 
				hid_r[row][col] == 255; 
			} 
			else if(res_r[row][col]  %  2 == 0)
			{ 
				hid_r[row][col] == 0;
			}
			if(res_b[row][col] %  2 == 1)
			{	 
				hid_b[row][col] == 255; 
			} 
			else if(res_b[row][col]  %  2 == 0)
			{ 
				hid_b[row][col] == 0;
			}  
			if(res_g[row][col] %  2 == 1)
			{	 
				hid_g[row][col] == 255; 
			} 
			else if(res_g[row][col]  %  2 == 0)
			{ 
				hid_g[row][col] == 0;
			}
		}
	}
}


void encode(char *ref_filename, char *hid_filename, char *enc_filename) 
{ 	
	unsigned int ref_r[ROWS][COLS]; 
	unsigned int ref_b[ROWS][COLS]; 
	unsigned int ref_g[ROWS][COLS]; 
	unsigned int hid_r[ROWS][COLS]; 
	unsigned int hid_g[ROWS][COLS]; 
	unsigned int hid_b[ROWS][COLS];
	unsigned int res_r[ROWS][COLS]; 
	unsigned int res_b[ROWS][COLS]; 
	unsigned int res_g[ROWS][COLS];  
	unsigned int image_width; 
	unsigned int image_height; 
	//open and reading in files 
	provided_read_png(ref_filename,ref_r, \
			   ref_g,ref_b, \  
			   &image_width,&image_height); 
	
	provided_read_png(hid_filename,hid_r[ROWS][COLS], \
			hid_g[ROWS][COLS],hid_b[ROWS][COLS], 
			   &image_width,&image_height); 
	//do steganography 
  	hide_image(ref_r[ROWS][COLS], ref_g[ROWS][COLS], \
			ref_b[ROWS][COLS], hid_r[ROWS][COLS], \ 
			hid_g[ROWS][COLS], hid_b[ROWS][COLS], \ 
			res_r[ROWS][COLS],res_g[ROWS][COLS], \
			res_b[ROWS][COLS],image_width, \ 
		image_height); 
	//write to out file 	 	
	provided_write_png(enc_filename, res_r[ROWS][COLS], res_b[ROWS][COLS], res_g[ROWS][COLS], image_width,  image_height); 
}
 
void decode(char *enc_filename, char *hid_filename)
{
	unsigned int enc_r[ROWS][COLS]; 
	unsigned int enc_g[ROWS][COLS]; 
	unsigned int enc_b[ROWS][COLS];	
	unsigned int hid_r[ROWS][COLS]; 
	unsigned int hid_g[ROWS][COLS]; 
	unsigned int hid_b[ROWS][COLS];
	unsigned int res_r[ROWS][COLS]; 
	unsigned int res_b[ROWS][COLS]; 
	unsigned int res_g[ROWS][COLS];  
	unsigned int image_height = 0; 
	unsigned int image_width = 0; 
	//open and reading in files 
	//provided_read_png(enc_filename,enc_r, \
			   enc_g,enc_b,
//			   &image_width,&image_height); 	
	//decode  
  	extract_image(res_r[ROWS][COLS],res_g[ROWS][COLS], 
			res_b[ROWS][COLS],hid_r[ROWS][COLS], \ 
			hid_g[ROWS][COLS], hid_b[ROWS][COLS], \ 
			image_width, image_height); 
	//write to out file 	 	
	provided_write_png(enc_filename, res_r[ROWS][COLS], res_b[ROWS][COLS],
					 res_g[ROWS][COLS], image_width, image_height);  
} 

