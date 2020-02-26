#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int sumFirstLast(int n)
{
    char *str = calloc(9, sizeof(int));
    snprintf(str, 9, "%i", n);
    return (str[0] - '0') + (str[strlen(str)-1] - '0');
}

int main()
{
    int T, N;
    scanf("%i", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%i", &N);
        printf("%i\n", sumFirstLast(N));
    }
    return 0;
}
