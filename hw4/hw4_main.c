#include <stdio.h> 
#include <stdlib.h> 
#include "hw4_provided.h" 
#include "hw4.h" 

int main()
{
	char ref_file[50] = "happyface.png";
	char hid_file[50] = "uchicago.png"; 
	char en_output[50] = "encode.png"; 
	surface_area_cylinder(1.0, 5.0);
	// add the rest of the function calls here
	encode("happyface.png","uchicago.png", "encode.png");
	decode("encode.png", "decode.png"); 
}
