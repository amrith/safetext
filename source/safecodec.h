/*
 * safecodec.h
 *
 * Part of the 'safetext' project. This project provides a simple set
 * of libraries that will encode arbitrary blocks of data into a
 * format that resembles base64. However it also implements a simple
 * form of codebook cipher that makes it harder to guess the input
 * data from the encoded output.
 *
 * This software is provided "as-is" with no warranties either
 * implied, or otherwise, on its applicability for use in any
 * situation. If you wish to use it, you do so entirely at your own
 * risk. The author assumes no liabilities for any damages that may
 * arise from your use of this software.
 *
 * This software is licensed under the terms of the license file
 * (LICENSE) provided in the root of this repository.
 *
 * Amrith. 2019-02-24
 *
 */


#ifndef __ST_SAFETEXT_H_DEFINED__
#define __ST_SAFETEXT_H_DEFINED__

char * safeencode (unsigned char * input, int input_length);
unsigned char * safedecode (char * input, int input_length,
                            int * output_length);

#endif
