/*
 * test-safetext.c
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


#include "safecodec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

#define ITERATIONS (100000)
#define STEP (2000)

int main ()
{
    int iteration, input_length, output_length, decoded_length, iix;
    char * input, * output, * decoded;

    srand(getpid());

    printf ( "|");
    for (iix = 0; iix < ITERATIONS/STEP; iix ++)
        printf ("-");
    printf ( "|\r|");

    for (iteration = 0; iteration < ITERATIONS; iteration ++)
    {
        if (iteration != 0)
        {
            input_length = rand() % 5000;

            if ((input = (char *) malloc(input_length+1)) == NULL)
            {
                perror ("malloc()");
                exit(1);
            }

            for (iix = 0; iix < input_length; iix ++)
                input[iix] = 'a' + random() % 26;
        }
        else
        {
            input_length = 0;
            input = NULL;
        }

        output = safeencode(input, input_length);

        decoded = safedecode(output, strlen(output), &decoded_length);

        if (input_length != decoded_length)
        {
            printf ( "test-safetext: length mismatch, expected %d, got %d\n",
                     input_length, decoded_length);
            assert(0);
        }

        if (memcmp(input, decoded, input_length))
        {
            printf ("test-safetext: decoded mismatch.\n" );
            assert(0);
        }

        free(input);
        free(output);
        free(decoded);
        if (iteration % STEP == 0)
        {
            printf (".");
            fflush (stdout);
        }
    }

    printf ( "\ntest-safetext: Test succeeded.\n" );
    return 0;
}

