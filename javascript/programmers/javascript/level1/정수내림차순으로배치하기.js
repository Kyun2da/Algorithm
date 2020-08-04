const n = 118372;

function solution(n) {
  var answer = 0;
  let string = String(n);
  let temp = [];
  temp = string.split("");
  temp.sort().reverse();
  answer = parseFloat(temp.join(""));
  return answer;
}

console.log(solution(n));
