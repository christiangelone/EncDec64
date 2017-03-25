/*
 * encdec.h
 *
 *  Created on: Mar 24, 2017
 *      Author: christian
 */

#ifndef ENCDEC_H_
#define ENCDEC_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	char * value;
} result;

static const char b64_table[] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
  'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
  'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
  'w', 'x', 'y', 'z', '0', '1', '2', '3',
  '4', '5', '6', '7', '8', '9', '+', '/'
};

char * encode64(const unsigned char * string, size_t len);
unsigned char * decode64(const char * string_base64, size_t len, size_t * decsize);

#endif /* ENCDEC_H_ */
