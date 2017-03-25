/*
 ============================================================================
 Name        : EncDec64bit.c
 Author      : Chrisian Angelone & Antonella Briglia
 Version     : 1.0
 Copyright   : MIT
 Description : Base64 Encoder & Decoder in C, Ansi-style
 ============================================================================
 */
#include "actions.h"
#include "options_list.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {

	fill_options_list(argc,argv);

	if(!is_option_key_present_in_options_list(OPT_DECODE)){
		add_option_to_front_of_options_list(OPT_DECODE);
	}

	if(wants_to_encode_from_std_to_std){

	}else
	if(wants_to_encode_from_std_to_std){

	}else
	if(wants_to_decode_from_file_to_file){

	}else
	if(wants_to_decode_from_file_to_file){

	}else
	if(wants_to_see_version){
		puts(VERSION);
	}else
	if(wants_to_see_help || this_guy_is_an_idiot){
		puts(HELP);
	}

	delete_options_list();
	return EXIT_SUCCESS;
}
