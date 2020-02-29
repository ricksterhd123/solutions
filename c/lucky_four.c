#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 9

int numberOfFours(char *str, int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] - '0' == 4)
            sum++;
    }
    return sum;
}

int main()
{
    int T, N;
    char *input_str = calloc(sizeof(char), MAX_LENGTH);
    scanf("%ld", &T);
    while (T--)
    {
        scanf("%d", &N);
        snprintf(input_str, 9, "%d", N);
        printf("%d\n", numberOfFours(input_str, strlen(input_str)));
    }
    return 0;
}

