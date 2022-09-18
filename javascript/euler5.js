function check(n, k) {
    for (let i = 1; i <= k; i++) {
        if (n % i !== 0) {
            return false;
        }
    }
    return true;
}

for (let i = 1; i < 2**32; i++) {
    if (check(i, 20)) {
        console.log(i);
        break;
    }
}
