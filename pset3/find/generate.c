/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Condition to make sure the user enters only one or two inputs when executing the program
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Extracting the number of random values to be generated from the command line arguement and saving it to integer variable.
    int n = atoi(argv[1]);

    // if seed value is given in command line, execute srand with the value by casting it to long int. 
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // generate random numbers n no.of times using drand.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}