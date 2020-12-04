#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Description: Checks if string is a palindrome
 * Params:
 * char* str - The string to check
 * int start - Index of first character
 * int end   - Index of last character
 * Returns int: 1 if string is palindrome otherwise 0
 */
int is_palindrome(char* str, int start, int end)
{
    if (end >= start && str[start] == str[end])
    {
        if (start == end || (end - start == 1 && strlen(str) % 2 == 0))
            return 1;
        else
            return is_palindrome(str, ++start, --end);
    } 
    else
    {
        return 0;
    }
}

/**
 * Description: Counts number of digits in number
 * Params: int n - The number whose digits to count
 * Returns int: number of digits
 */
int digits (int n) {
    return (int) floor(log10(abs(n))) + 1;
}

int main()
{
    int i, j, product, palindrome, result;
    i = j = product = palindrome = result = 0;

    for (i = 999; i >= 100; i--)
    {
        for (j = 999; j >= 100; j--)
        {
            product = i * j;
            char* numstr = (char*) calloc(digits(product), sizeof(char));
            assert(numstr);

            snprintf(numstr, sizeof(numstr), "%i", product);
            palindrome = is_palindrome(numstr, 0, strlen(numstr)-1);
            numstr = 0;
            free(numstr);

            if (palindrome && product > result)
                result = product;
        }
    }

    printf("%i", result);
    return 0;
}