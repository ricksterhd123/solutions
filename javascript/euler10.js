function factors(MAX_SIEVE_SIZE = 2 ** 25) {
    let primes = [];
    let sieve = [];

    for (let i = 0; i < MAX_SIEVE_SIZE; i++) {
        sieve[i] = true;
    }

    sieve[0] = sieve[1] = false;

    let p = 2;

    do {
        primes.push(p);

        for (let i = 2*p; i < MAX_SIEVE_SIZE; i += p) {
            sieve[i] = false;
        }

        do {
            p++;
        } while (sieve[p] == false);
    } while (p < MAX_SIEVE_SIZE);

    return primes;
}

let sum = 0;
factors().filter((x) => x < 2000000).forEach((x) => sum+=x);
console.log(sum);
