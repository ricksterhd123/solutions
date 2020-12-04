#include <stdio.h>
#include <time.h>

/**
 * Brute-forced euler 5 solution
 * Takes ~19.31 seconds on my machine
 */

int main()
{
    
    unsigned long max = 18446744073709551615;
    unsigned long result = 0;
    int divisors = 20;

    clock_t begin = clock();
    for (unsigned long i = 1; i <= max; i++)
    {
        int divisible = 1;
        for (int j = 1; j <= divisors ; j++)
        {
            if (i % j != 0)
                divisible = 0;
        }

        if (divisible)
        {
            result = i;
            break;
        }
    }
    
    clock_t end = clock();

    printf("Result: %i\n", result);
    printf("Time taken: %f", (double) (end - begin)/CLOCKS_PER_SEC);
    return 0;
}
