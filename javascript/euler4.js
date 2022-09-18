function digit(a, b) {
    return Math.floor(a / (10**(b - 1)) % 10);
}

function isPalindrome(n) {
    const digits = Math.floor(Math.log10(n) + 1);

    for (let i = 0; i < (digits + 1) / 2; i++){
        const a = digit(n, digits-i);
        const b = digit(n, i + 1);
        if (a !== b) {
            return false;
        }
    }

    return true;
}

let result = 1;
for (let i = 100; i <= 999; i++) {
    for (let j = 100; j <= 999; j++) {
        const product = i * j;
        if (isPalindrome(product) && product > result) {
            result = product;
        }
    }
}

console.time('result');
console.log(result);
console.timeEnd('result');
