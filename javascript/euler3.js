function factors(n, MAX_SIEVE_SIZE = 2 ** 16) {
    let factors = [];
    let primes = [];
    let sieve = [];

    for (let i = 0; i < MAX_SIEVE_SIZE; i++) {
        sieve[i] = true;
    }

    sieve[0] = sieve[1] = false;

    let p = 2;

    do {
        primes.push(p);

        if (n % p == 0) {
            factors.push(p);
        }

        delete sieve[p];

        for (let i = 2*p; i < MAX_SIEVE_SIZE; i += p) {
            sieve[i] = false;
        }

        do {
            p++;
        } while (sieve[p] == false);
    } while (p < MAX_SIEVE_SIZE);

    return factors;
}

(() => {
    console.time('prime');
    console.log(factors(600851475143));
    console.timeEnd('prime');
})();
