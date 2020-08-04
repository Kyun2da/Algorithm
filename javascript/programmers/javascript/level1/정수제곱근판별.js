const n = 121;

function solution(n) {
  if (Number.isInteger(Math.sqrt(n))) {
    return Math.pow(Math.sqrt(n) + 1, 2);
  }
  return -1;
}

console.log(solution(n));
