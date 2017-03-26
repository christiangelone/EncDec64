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
#include "encdec.h"
#include <stdlib.h>

int read_from_ifile_write_to_ofile(char* ifile, char* ofile, int action){
	FILE* inputfp = fopen(ifile,"r");
	if(inputfp){
		size_t length = 1024;
		FILE* outputfp = fopen(ofile,"w");
		char* line = (char*)malloc(sizeof(char)*length);
		if(line == NULL){
			puts("Memory error\n");
			return -1;
		}
		if(outputfp){
			while(fgets(line, length, inputfp) != NULL){
				char* result;
				if(action == 1){
					result = encode64(line,strlen(line));
				}else{
					result = decode64(line,strlen(line),NULL);
				}
				fputs(result,outputfp);
				free(result);
			}
		}
		free(line);
		fclose(outputfp);
		fclose(inputfp);
		return 0;
	}
	puts("Error, no input file\n");
	return -1;
}

int main(int argc, char *argv[]) {

	fill_options_list(argc,argv);

	if(is_empty_options_list()){
		add_option_to_front_of_options_list(OPT_ENCODE);
	}

	analize_options();

	if(wants_to_decode_from_istd_to_ostd){

		char istd[1024];
		scanf("%1024s",istd);
		char * decoded = decode64(istd,strlen(istd),NULL);
		printf("%s",decoded);
		free(decoded);

		//puts("Decoding...");
		//puts("Printing char * to ostd");

	}else if(wants_to_encode_from_istd_to_ostd){

		char istd[1024];
		scanf("%1024s",istd);
		char * encoded = encode64(istd,strlen(istd));
		printf("%s",encoded);
		free(encoded);
		//puts("Encoding...");
		//puts("Printing char * to ostd");

	}else if(wants_to_decode_from_ifile_to_ofile){

		char * ifilename = get_option_value_from_options_list(OPT_INPUT);
		if(ifilename == NULL) ifilename = get_option_value_from_options_list(OPT_INPUT_);

		char * ofilename = get_option_value_from_options_list(OPT_OUTPUT);
		if(ofilename == NULL) ofilename = get_option_value_from_options_list(OPT_OUTPUT_);

		printf("(ifile: %s, ofile: %s)\n",ifilename,ofilename);

		read_from_ifile_write_to_ofile(ifilename,ofilename,0);

		puts("Reading ifile bytes...");
		puts("Decoding...");
		puts("Writing char * to ofile");

	}else if(wants_to_encode_from_ifile_to_ofile){

		char * ifilename = get_option_value_from_options_list(OPT_INPUT);
		if(ifilename == NULL) ifilename = get_option_value_from_options_list(OPT_INPUT_);

		char * ofilename = get_option_value_from_options_list(OPT_OUTPUT);
		if(ofilename == NULL) ofilename = get_option_value_from_options_list(OPT_OUTPUT_);

		printf("(ifile: %s, ofile: %s)\n",ifilename,ofilename);

		read_from_ifile_write_to_ofile(ifilename,ofilename,1);

		puts("Reading ifile bytes...");
		puts("Encoding...");
		puts("Writing char * to ofile");

	}else if(wants_to_see_version){
		puts(VERSION);

	}else if(wants_to_see_help || this_guy_is_an_idiot){
		puts(HELP);
	}else{
		puts("ALGO PASO!");
	}

	delete_options_list();
	return EXIT_SUCCESS;
}
