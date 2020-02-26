#include <stdio.h>

int main()
{
    int T, A, B;
    scanf("%i", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%i %i", &A, &B);
        printf("%i\n", A % B);
    }

    return 0;
}