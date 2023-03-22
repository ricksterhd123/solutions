#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define COUNT_OF(x) ((sizeof(x) / sizeof(0 [x])) / ((size_t)(!(sizeof(x) % sizeof(0 [x])))))

void printiarr(char *message, int *iarr, int count)
{
    printf("%s [", message);
    for (int i = 0; i < count; i++)
    {
        printf((i == count - 1) ? "%d]\n" : "%d, ", iarr[i]);
    }
}

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    // Oversize by default
    // We could skip this by checking the most significant digits
    int *result = (int *)malloc(sizeof(int) * (digitsSize + 1));
    int carry = 1;

    for (int i = digitsSize; i >= 0; i--)
    {
        result[i] = ((i > 0) ? digits[i - 1] : 0) + carry;
        carry = (result[i] > 9) ? result[i] - 9 : 0;
        result[i] %= 10;
    }

    // Create a copy with -1 size
    if (result[0] <= 0)
    {
        *returnSize = digitsSize;
        int *resultNorm = (int *)malloc(sizeof(int) * digitsSize);
        memcpy(resultNorm, result + 1, digitsSize * sizeof(int));
        free(result);
        return resultNorm;
    }

    *returnSize = digitsSize + 1;

    return result;
}

int main()
{
    int *returnSize = (int *)malloc(sizeof(int));

    int input[] = {9, 9, 9, 9};
    int *output = plusOne(input, COUNT_OF(input), returnSize);

    printiarr("Input", input, COUNT_OF(input));

    printf("Return size %d\n", *returnSize);

    printiarr("Output", output, *returnSize);

    free(output);
    free(returnSize);

    return 0;
}
