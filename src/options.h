/*
 * options.h
 *
 *  Created on: Mar 24, 2017
 *      Author: christian
 */

#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char * key;
	char * value;
} option;

const option OPT_DECODE   = (option){ .key = "-a",        .value = "decode"};
const option OPT_ENCODE   = (option){ .key = "-a",        .value = "encode"};
const option OPT_INPUT    = (option){ .key = "-i",        .value = NULL};
const option OPT_INPUT_   = (option){ .key = "--input",   .value = NULL};
const option OPT_OUTPUT   = (option){ .key = "-o", 	      .value = NULL};
const option OPT_OUTPUT_  = (option){ .key = "--output",  .value = NULL};
const option OPT_HELP  	  = (option){ .key = "-h", 	      .value = NULL};
const option OPT_HELP_    = (option){ .key = "--help",    .value = NULL};
const option OPT_VERSION  = (option){ .key = "-v",        .value = NULL};
const option OPT_VERSION_ = (option){ .key = "--version", .value = NULL};

int optcmp_key(option opta,option optb){
	return (strcmp(opta.key,optb.key) == 0);
}

int optcmp_value(option opta,option optb){
	return (strcmp(opta.value,optb.value) == 0);
}

int optcmp(option opta,option optb){
	return (strcmp(opta.key,optb.key) == 0 && strcmp(opta.value,optb.value) == 0);
}

#endif /* OPTIONS_H_ */
