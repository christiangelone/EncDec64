/*
 * encdec.h
 *
 *  Created on: Mar 24, 2017
 *      Author: christian
 */

#ifndef ENCDEC_H_
#define ENCDEC_H_

typedef struct {
	char * value;
} result;

static const char cb64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void encode64(const unsigned char * string_256);
void decode(const unsigned char * string_64);

#endif /* ENCDEC_H_ */
