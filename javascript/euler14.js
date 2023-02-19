function getCollatzSequence(n) {
    let tn = n;
    let count = 1; // itself first in sequence

    while (tn > 1) {
        if (tn % 2 === 0) {
            tn /= 2;
        } else {
            tn = 3 * tn + 1;
        }
        count++;
    }

    return count;
}

function maxCollatzSequence(n) {
    let maxCN = -Infinity;
    let maxCI = -Infinity;

    for (let i = 1; i < n; i++) {
        const cn = getCollatzSequence(i);
        if (cn > maxCN) {
            maxCN = cn;
            maxCI = i;
        }
    }

    return maxCI;
}

console.log(maxCollatzSequence(1000000));

