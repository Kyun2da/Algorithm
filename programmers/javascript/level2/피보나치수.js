const n = 3;

const solution = (n) => {
  let prev1 = 0,
    prev2 = 1;
  let val = 0;
  for (let i = 2; i <= n; i++) {
    val = prev1 + prev2;
    prev1 = prev2 % 1234567;
    prev2 = val % 1234567;
  }
  return val % 1234567;
};

console.log(solution(n));
