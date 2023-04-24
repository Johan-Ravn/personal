
const memo = {};

function fib(n) {
    if (n === 0) return 0;
    if (n <= 1) return 1;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}

let num = 1000;

for (let i = 0; i < num; i++) {
    console.log(fib(i));
}
