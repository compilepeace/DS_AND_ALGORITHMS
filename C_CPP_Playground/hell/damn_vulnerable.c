// Author : Abhinav Thakur
// Email  : compilepeace@gmail.com

// Description : This program is used to demonstrate how a program as simple as this one can give 
//				 root priveleges to an attacker.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "color.h"


int main(int argc, char *argv[])
{
	char user_input[100];


	// Check if the user provided the command line argument. If user input is not provided 
	// Print a Usage message and halt the program with exit status 16
	if (argc < 2)
	{
		fprintf(stderr, RED"[-]"RESET" Usage: %s <InputString>\n", argv[0]);
		exit(0x10);			
	}


	// Copy the input provided by user into an array of 100 bytes
	// A better option would be to use strncpy(): see man strncpy
	strcpy(user_input, argv[1]);

	
	// Print the user provided string nicely	
	fprintf(stdout, GREEN"[+]"RESET" User gave input : "YELLOW"%s\n", user_input );


// Return with exit status 0 if everything works successfully
return 0;
}
