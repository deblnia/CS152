#ifndef HW4_H
#define HW4_H
#define ROWS 50 
#define COLS 50

/* surface_area_cylinder
 * Calculates the surface area of a cylinder given height and radius
 * inputs: height, radius
 * output: double
 */
double surface_area_cylinder(double height, double radius);


/* hides images
 * inputs: 
	uint ref_r - 2x2 array of red pixels in ref image
	uint ref_b - 2x2 array of blue pixels in ref image
	uint ref_g - 2x2 array of green pixels in ref imag
	uint hid_r - 2x2 array of red pixels in hid image
	uint hid_b - 2x2 array of blue pixels in hid image
	uint hid_g - 2x2 array of green pixels in hid image
	uint res_r - 2x2 array of red pixels in result image	
	uint res_b - 2x2 array of blue pixels in result image
	uint res_g - 2x2 array of green pixels in result image
	int height - height of image 
	int width  - width of image
* Output: 
* 	none -- void 
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
	unsigned int height, unsigned int width);

/* extract images
 * inputs: 
	uint hid_r - 2x2 array of red pixels in hid image
	uint hid_b - 2x2 array of blue pixels in hid image
	uint hid_g - 2x2 array of green pixels in hid image
	uint res_r - 2x2 array of red pixels in result image	
	uint res_b - 2x2 array of blue pixels in result image
	uint res_g - 2x2 array of green pixels in result image
	int height - height of image 
	int width  - width of image
* Output: 
* 	none -- void 
*/ 

void extract_image(
	unsigned int res_r[ROWS][COLS], 
	unsigned int res_g[ROWS][COLS], 
	unsigned int res_b[ROWS][COLS], 
	unsigned int hid_r[ROWS][COLS], 
	unsigned int hid_g[ROWS][COLS], 
	unsigned int hid_b[ROWS][COLS], 
	unsigned int height, unsigned int width);

/* encode
 * inputs: 
	ref_filename - referenence image filename 
	hid_filename - hidden image filename 
	enc_filename - encoded image filename  
* Output: 
* 	none -- void 
*/ 

void encode(char *ref_filename, char *hid_filename, char *enc_filename);

/* decode
 * inputs: 
	hid_filename - hidden image filename 
	enc_filename - encoded image filename  
* Output: 
* 	none -- void 
*/ 
void decode(char *enc_filename, char *hid_filename);


#endif

