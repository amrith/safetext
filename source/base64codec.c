/*
 * base64codec.c
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


#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include "codebook.h"

#include "base64codec.h"

static char codebook_lookup(codebook_t * c, unsigned char i)
{
    assert(i < CHARSET_LENGTH);
    return(c->alphabet[i]);
}

static unsigned char codebook_reverse(codebook_t * c, char i)
{
    int ix = __charix(i);
    return c->reverse[ix];
}

int _encode64 ( unsigned char * input, unsigned int input_length,
                char * output, unsigned int output_length,
                codebook_t * codebook )
{
    int iix, oix, tix, qix, olen;
    uint32_t t;

    for (oix = 0, iix = 0; iix < input_length; /* ... */)
    {
        for (t = 0, tix = 0; tix < 3 && iix < input_length; tix ++, iix ++)
            t += (input[iix] << (8 * (2 - tix)));

        /* tix is now 1, 2, or 3, indicating how many bytes have been read */
        /* treat the three bytes in triple, as a quad of 64 bits each */
        for (qix = 3; qix >= 0; qix --, tix --, oix ++)
        {
            if (oix >= output_length)
            {
                fprintf(stderr, "ERROR: Output buffer too small.\n");
                return -1;
            }

            if (tix >= 0)
                output[oix] = codebook_lookup(codebook,
                                              (t >> (qix * 6)) & 0x3F);
            else
                output[oix] = PAD_CHARACTER;
        }
    }

    return oix;
}

int _decode64 ( char * input, unsigned int input_length,
                char * output, unsigned int output_length,
                codebook_t * codebook )
{
    int olen, iix, oix, tix, qix;
    int t;

    if (input_length % 4)
    {
        fprintf ( stderr, "ERROR: Invalid input length.\n" );
        return -1;
    }

    for (iix = 0, oix = 0; iix < input_length; /* ... */)
    {
        for (t = 0, qix = 0; qix < 4 && iix < input_length; iix ++)
        {
            if (input[iix] != PAD_CHARACTER)
            {
                t += (codebook_reverse(codebook,
                                       input[iix]) << (6 * (3 - qix)));
                qix ++;
            }
        }

        /* qix now has either 2, 3, or 4 indicating the number of b64
         * characters that was read */
        assert(qix >= 2 && qix <= 4);

        for (tix = 0; tix < qix - 1; tix ++)
        {
            if (oix >= output_length)
            {
                fprintf(stderr, "ERROR: Output buffer too small.\n");
                return -1;
            }

            output[oix++] = (t >> (2 - tix) * 8) & 0xFF;
        }
    }

    return oix;
}

unsigned int _encode64_length (unsigned int input_length)
{
    return (4 * ((input_length + 2)/3));
}

unsigned int _decode64_length (unsigned int input_length)
{
    return (((input_length + 3) / 4) * 3);
}
