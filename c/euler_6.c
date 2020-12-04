#include <stdio.h>
#include <math.h>
#include <time.h>

double sum_of_squares(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += pow(i, 2);
    }
    return sum;
}

int main()
{
    int n = 100;
    double result = 0;
    clock_t begin = clock();
    result = pow((n * (n + 1)) / 2, 2) - sum_of_squares(n);
    clock_t end = clock();
    printf("Result: %f\n", result);
    printf("Time taken: %f", (double) (end - begin)/CLOCKS_PER_SEC);
    return 0;
}