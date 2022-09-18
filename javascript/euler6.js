function squareOfSum(n) {
    return ((n*(n+1))/2) ** 2;
}
function sumOfSquare(n) {
    let sum = 0;
    for (let i = 1; i <= n; i++) {
        sum += i**2;
    }
    return sum;
}

let n = 100;
console.log(squareOfSum(n) - sumOfSquare(n));
