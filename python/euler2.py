import functools

# can this be done in O(log(n))?
# https://en.wikipedia.org/wiki/Fibonacci_number#Matrix_form
# https://www.cs.utexas.edu/users/EWD/ewd06xx/EWD654.PDF

@functools.lru_cache(maxsize=None)
def fib(n):
    if n < 2:
        return n
    return fib(n-2) + fib(n-1)

i = x = sum = 0
n = 4000000
while x <= n:
    if x % 2 == 0:
        sum += x
    x = fib(i)
    i += 1
print(sum)