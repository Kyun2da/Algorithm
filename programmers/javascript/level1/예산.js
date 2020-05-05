const d = [5, 4, 3, 2, 1];
const budget = 10;

function solution(d, budget) {
  var answer = 0;
  d.sort((a, b) => a - b);
  while (budget >= d[0] && d.length >= 1) {
    budget -= d[0];
    d.splice(0, 1);
    answer++;
  }
  return answer;
}

console.log(solution(d, budget));
