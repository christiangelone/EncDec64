/*
 * about.h
 *
 *  Created on: Mar 24, 2017
 *      Author: christian
 */

#ifndef ABOUT_H_
#define ABOUT_H_

const char * VERSION = "1.0";


const char * HELP = " Usage: \n \
   tp0 -h \n \
   tp0 -V \n \
   tp0 [options] \n \
Options: \n \
  -V, --version Print version and quit.\n \
  -h, --help Print this information. \n \
  -i, --input Location of the input file. \n \
  -o, --output Location of the output file. \n \
  -a, --action Program action: encode (default) or decode. \n \
Examples: \n \
  tp0 -a encode -i ~/input -o ~/output \n \
  tp0 -a decode";

#endif /* ABOUT_H_ */
