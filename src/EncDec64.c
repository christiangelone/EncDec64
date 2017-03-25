/*
 ============================================================================
 Name        : EncDec64bit.c
 Author      : Chrisian Angelone & Antonella Briglia
 Version     : 1.0
 Copyright   : MIT
 Description : Base64 Encoder & Decoder in C, Ansi-style
 ============================================================================
 */

#include "options_list.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {

	fill_options_list(argc,argv);
	options * opts = get_options_list();

	int i = 0;
	while(i < size_of_options_list()){
		option opt = get_option_from_options_list(i);
		printf("(Key: %s,Value: %s)\n",opt.key,opt.value);
		i++;
	}

	//-------------------------------------
		delete_options_list();

	puts("-------------------------------");
	puts("           FINISHED            ");
	puts("-------------------------------");

	return EXIT_SUCCESS;
}
