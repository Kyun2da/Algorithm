const x = 2;
const n = 5;

function solution(x, n) {
  var answer = [];
  for (let i = 1; i <= n; i++) {
    answer.push(x * i);
  }
  return answer;
}

console.log(solution(x, n));
