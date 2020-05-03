const num = -10;

function solution(num) {
  var answer = "";
  if (num % 2 === -1 || num % 2 === 1) answer = "Odd";
  else answer = "Even";
  return answer;
}

console.log(solution(num));
