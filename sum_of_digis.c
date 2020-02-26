#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int sumOfDigits(int n)
{
    int sum = 0;
    char *str;
    str = calloc(9, sizeof(int));
    snprintf(str, 9, "%i", n);
    for (int i = 0; i < strlen(str); i++)
    {
        sum += str[i] - '0';
    }
    return sum;
}

int main()
{
    int N, T;
    scanf("%i", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%i", &N);
        int result = sumOfDigits(N);
        printf("%i\n", result);
    }
    return 0;
}