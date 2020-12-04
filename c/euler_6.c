#include <stdio.h>
#include <math.h>

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
    result = pow((n * (n + 1)) / 2, 2) - sum_of_squares(n);
    printf("Result: %f\n", result);    
    return 0;
}