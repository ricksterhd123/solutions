/*
Greatest prime factor algorithm using sieve of eratosthenes
*/
#include <stdbool.h>
#include <stdio.h>

struct primeSquare {
    int value;
    bool marked;
};

/*
Find all prime numbers below n.
assume arr is just a null pointer, we resize it dynamically and return its length.
Returns length of arr
*/
int sieve(int n, int* arr) {
    // Setup the result
    int size = 0;
    arr = (int) calloc(sizeof(int), size);  // ive heard this returns NULL

    if (arr == NULL) {
        fprintf(stderr, "Fatal error: could not allocate memory...");
        free(arr);
        return -1;
    }

    // setup the primeSquares
    // n-1 because the list is from [2..n]
    struct primeSquare* list = calloc(sizeof(struct primeSquare), n-1);
    for (int i = 0; i < n-1; i++) {
        (list + i)->value = 2 + i;
        (list + i)->marked = false; 
    }

    // Start from 2, the smallest prime number
    int p = 2;
    bool finished = false;

    do {
        int start = 2*p - 2;
        for (int i = start; i < n-1; i += p)
        {
            (list + i)->marked = true;  // mark them
        }

        // search for the first number greater than p in the list unmarked
        int newp = p;
        
        for (int i = 0; i < n-1; i++) {
            if ((list+i)->value > newp)
            {  
                newp = (list+i)->value;
                break; 
            }
        }

        // check if the next prime next prime has been found
        if (p == newp)
            finished = true;
        else
            p = newp;

    } while (!finished);


    for (int i = 0; i < n-1; i++) {
        if ((list+i)->marked)
        {
            arr = realloc(arr, ++size);
            if (arr == NULL) {
                fprintf(stderr, "Fatal error: could not allocate memory...");
                free(arr);
                free(list);
                return -1;
            }
            *(arr + size - 1) = (list+i)->value;
        }
    }

    free(list);
    return size;
}

int main()
{
    int* arr;
    int n;

    do {
        sscanf("Enter a positive integer: ", "%d", &n);
    } while (n == NULL || n <= 1);

    printf("+======================================\n");
    printf("+ Recieved: %d\n", n);
    printf("+======================================\n");
    printf("+ Prime numbers from 2 to %d:\n", n);
    printf("+======================================\n");
    int length = sieve(n, arr);
    if (length == -1) {
        fprintf(stderr, "Could not sieve...");
        free(arr);
        return -1;
    }

    for (int i = 0; i < length; i++) {
        printf("+ [%d]: %d\n", i, *(arr+i));
    }
    printf("+======================================\n");
    return 0;
}