import math

def sieve(n):
    primes = []
    A = [True for x in range(n+1)]
    A[0] = A[1] = False # 0 and 1 are not prime
    for i in range(2, math.ceil(math.sqrt(n))):
        if A[i]:
            for j in range(i**2, n+1, i):
                A[j] = False   
    for i in range(len(A)):
        if A[i]:
            primes.append(i)
    return primes

def factor(n):
    primes = sieve(n)
    factors = []
    while n != 1:
        for i in range(len(primes)):
            if n % primes[i] == 0:
                n /= primes[i]
                factors.append(primes[i])
                break
    return factors

# Shallow test
print(sieve(10) == [2, 3, 5, 7])    
print(factor(200) == [2,2,2,5,5])
print(factor(13195) == [5,7,13,29])

print(sieve(600851475143))