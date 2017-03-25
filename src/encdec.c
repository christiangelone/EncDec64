/*
 * encdec.c
 *
 *  Created on: Mar 24, 2017
 *      Author: christian
 */

#include <stdio.h>;
#include "encdec.h";

/*
* encode 3 8-bit binary bytes as 4 '6-bit' characters
*/
//static void encodeblock( unsigned char *in, unsigned char *out, int len ){
//    out[0] = (unsigned char) cb64[ (int)(in[0] >> 2) ];
//    out[1] = (unsigned char) cb64[ (int)(((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4)) ];
//    out[2] = (unsigned char) (len > 1 ? cb64[ (int)(((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6)) ] : '=');
//    out[3] = (unsigned char) (len > 2 ? cb64[ (int)(in[2] & 0x3f) ] : '=');
//}

/*
* decode 4 '6-bit' characters into 3 8-bit binary bytes
*/
//static void decodeblock( unsigned char *in, unsigned char *out ){
//    out[ 0 ] = (unsigned char ) (in[0] << 2 | in[1] >> 4);
//    out[ 1 ] = (unsigned char ) (in[1] << 4 | in[2] >> 2);
//    out[ 2 ] = (unsigned char ) (((in[2] << 6) & 0xc0) | in[3]);
//}

void encode64(const unsigned char * string){
	//return NULL;
	return;
}
void decode(const unsigned char * string_64){
	return;
	//return NULL;
}
