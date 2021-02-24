import math

def sieve(n):
    A = [True for x in range(n)]
    
    for i in range(2, math.ceil(math.sqrt(n))):
        if A[i]:
            for j in range(i**2, n, i):
                A[j] = False

    primes = []
    for i in range(2, len(A)):
        if A[i]:
            primes.append(i)
        
    return primes

def sum_primes(n):
    sum = 0
    
    for p in sieve(n):
        sum += p
        
    return sum
