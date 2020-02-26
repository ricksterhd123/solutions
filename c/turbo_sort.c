#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
    int T, num, i;
    scanf("%i", &T);
    int *arr = calloc(T, sizeof(int));
    for (i = 0; i < T; i++)
    {
        scanf("%i", arr + i);
    }

    qsort(arr, T, sizeof(int), cmpfunc);

    for (i = 0; i < T; i++)
    {
        printf("%i\n", *(arr + i));
    }
}