#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    if (n <= 1 ) 
        return 1;
    else 
        return n * factorial(n-1);
}

int main()
{
    int testcases, n;
    scanf("%i", &testcases);
    for (int i = 0; i < testcases; i++)
    {
        scanf("%i", &n);
        printf("%i", factorial(n));
    }
    return 0;
}