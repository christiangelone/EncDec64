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
#include <stdlib.h>

int main(int argc, char *argv[]) {

	fill_options_list(argc,argv);

	if(is_empty_options_list()){
		add_option_to_front_of_options_list(OPT_DECODE);
	}

	analize_options();

	if(wants_to_decode_from_istd_to_ostd){
		char istd[1024];
		scanf("%1024s",istd);
		printf("%s\n",istd);
		puts("Executing char * decode(char * string) with istd bytes");
		puts("Printing char * to ostd");

	}else if(wants_to_encode_from_istd_to_ostd){
		puts("Executing char * encode(char * string) with istd bytes");
		puts("Printing char * to ostd");

	}else if(wants_to_decode_from_ifile_to_ofile){
		puts("Reading ifile bytes...");
		puts("Executing char * encode(char * string) with ifile bytes...");
		puts("Writing char * to ofile");

	}else if(wants_to_decode_from_ifile_to_ofile){
		puts("Reading ifile bytes...");
		puts("Executing char * decode(char * string) with ifile bytes...");
		puts("Writing char * to ofile");

	}else if(wants_to_see_version){
		puts(VERSION);

	}else if(wants_to_see_help || this_guy_is_an_idiot){
		puts(HELP);
	}

	delete_options_list();
	return EXIT_SUCCESS;
}
