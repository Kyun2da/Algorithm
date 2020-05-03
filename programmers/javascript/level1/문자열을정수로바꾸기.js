const s = "-1234";

function solution(s) {
  let answer = 0;
  if (s[0] === "-" || s[0] === "+") {
    answer = parseInt(s.substring(1));
    if (s[0] === "-") answer *= -1;
  } else answer = parseInt(s);
  return answer;
}

console.log(solution(s));
