/*
 * safecodec.c
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


#include "base64codec.h"
#include "codebook.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "safecodec.h"

char * safeencode (unsigned char * input, int input_length)
{
    char * output, ch;
    uint16_t payload[3];
    int cb, output_length;

    cb = rand() % CODEBOOK_SIZE;

    payload[0] = (uint16_t) cb;
    payload[1] = rand();
    payload[2] = rand();

    output_length = 8 + _encode64_length(input_length);
    if ((output = malloc(output_length+1)) == NULL)
    {
        perror ("malloc");
        return NULL;
    }

    if (_encode64((unsigned char *)payload, 3 * sizeof(uint16_t), output, 8,
                  codebook + 0) < 0)
    {
        free(output);
        return NULL;
    }

    if (_encode64(input, input_length, output + 8,
                  ((input_length + 2)/3) * 4 + 1, codebook + cb) < 0)
    {
        free(output);
        return NULL;
    }

    output[output_length] = 0;
    return (output);
}

unsigned char * safedecode (char * input, int input_length,
                            int * output_length)
{
    uint16_t payload[3];
    int encoded_length;
    unsigned char * output;

    if(_decode64(input, 8, (unsigned char *)payload, 6, codebook + 0) != 6)
    {
        printf ( "safedecode: Error decoding input.\n" );
        return NULL;
    }

    encoded_length = input_length - 8;
    assert(encoded_length % 4 == 0);

    *output_length = _decode64_length(encoded_length);
    if ((output = malloc(*output_length + 1)) == NULL)
    {
        perror("malloc()");
        return NULL;
    }

    if ((*output_length = _decode64(input + 8, encoded_length,
                                    output, *output_length,
                                    codebook + payload[0])) < 0)
    {
        free(output);
        return NULL;
    }

    output[*output_length] = 0;
    return output;
}
