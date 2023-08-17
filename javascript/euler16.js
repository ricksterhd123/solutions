// https://stackoverflow.com/questions/70382306/logarithm-of-a-bigint
function log10(bigint) {
    if (bigint < 0) {
        return NaN;
    }

    const s = bigint.toString(10);
    return s.length + Math.log10("0." + s.substring(0, 15))
}

function getSumOfDigits(number) {
    const digits = number.toString(10);

    let sum = 0;
    for (let i = 0; i < digits.length; i++) {
        sum += Number(digits[i]);
    }

    return sum;
}

console.log(getSumOfDigits(BigInt(2**1000)));
