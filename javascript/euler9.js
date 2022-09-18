const triplets = [];

let a = 1;
let b = 2;
let c = 0;

const max = 1000;

for (let a = 1; a <= max; a++) {
    for (let b = 1; b <= max; b++) {
        c = Math.sqrt(a**2 + b**2);
        if (c % 1 === 0) {
            triplets.push([a, b, c]);
        }
    }
}

[a, b, c] = triplets.find((x) => (x[0]+x[1]+x[2]) === 1000);
console.log(a*b*c);
