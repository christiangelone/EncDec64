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

	while(opts != NULL){
		puts("Key:");
		puts(opts->opt.key);
		puts("Value:");
		if(opts->opt.value != NULL){
			puts(opts->opt.value);
		}else{
			puts("NULL");
		}
		opts = opts->next;
	}

	//-------------------------------------
		delete_options_list();

	puts("-------------------------------");
	puts("           FINISHED            ");
	puts("-------------------------------");

	return EXIT_SUCCESS;
}
