/*
 * actions.h
 *
 *  Created on: Mar 24, 2017
 *      Author: christian
 */

#ifndef ACTIONS_H_
#define ACTIONS_H_

#include "about.h"
#include "options_list.h"

int wants_to_encode_from_istd_to_ostd = 0;
int wants_to_encode_from_ifile_to_ofile = 0;
int wants_to_decode_from_istd_to_ostd = 0;
int wants_to_decode_from_ifile_to_ofile = 0;
int wants_to_see_version = 0;
int wants_to_see_help = 0;
int this_guy_is_an_idiot = 0;

void analize_options(){

	int decode_action_present = 0;
	int encode_action_present = 0;

	int input_key_present = 0;
	int output_key_present = 0;

	int version_key_present = 0;
	int help_key_present = 0;

	int i = 0;
	while(i < size_of_options_list()){

		option opt = get_option_from_options_list(i);

		if(optcmp(opt,OPT_DECODE)){
			decode_action_present = 1;
		}
		else if(optcmp(opt,OPT_ENCODE)){
			encode_action_present = 1;
		}
		else if(optcmp_key(opt,OPT_INPUT) || optcmp_key(opt,OPT_INPUT_)){
			input_key_present = 1;
		}
		else if(optcmp_key(opt,OPT_OUTPUT) || optcmp_key(opt,OPT_OUTPUT_)){
			output_key_present = 1;
		}
		else if(optcmp_key(opt,OPT_VERSION) || optcmp_key(opt,OPT_VERSION_)){
			version_key_present = 1;
		}
		else{
			help_key_present = optcmp_key(opt,OPT_HELP) || optcmp_key(opt,OPT_HELP_);
		}

		//printf("(KEY: %s, VALUE: %s)\n",opt.key,opt.value);
		i++;
	}

	if(version_key_present && size_of_options_list() == 1){
		//puts("WANTS TO SEE VERSION");
		wants_to_see_version = 1;

	}else if(help_key_present && size_of_options_list() == 1){
		//puts("WANTS TO SEE HELP");
		wants_to_see_help = 1;

	}else if(decode_action_present && !input_key_present && !output_key_present){
		//puts("WANTS TO DECODE FROM STD TO STD");
		wants_to_decode_from_istd_to_ostd = 1;

	}else if(decode_action_present && input_key_present && output_key_present){
		//puts("WANTS TO DECODE FROM IFILE TO OFILE");
		wants_to_decode_from_ifile_to_ofile = 1;

	}else if(encode_action_present && !input_key_present && !output_key_present){
		//puts("WANTS TO ENCODE FROM STD TO STD");
		wants_to_encode_from_istd_to_ostd = 1;

	}else if(encode_action_present && input_key_present && output_key_present){
		//puts("WANTS TO ENCODE FROM IFILE TO OFILE");
		wants_to_encode_from_ifile_to_ofile = 1;
	}else{
		//puts("THIS GUY IS AN IDIOT");
		this_guy_is_an_idiot = 1;
	}
}

#endif /* ACTIONS_H_ */
