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

int main(void) {

	option opt1;
	opt1.key = "-h";
	opt1.value = NULL;

	add_option_to_option_list(opt1);

	options * opts = get_option_list();

	while(opts != NULL){
		puts(opts->opt.key);
		opts = opts->next;
	}

	return EXIT_SUCCESS;
}
