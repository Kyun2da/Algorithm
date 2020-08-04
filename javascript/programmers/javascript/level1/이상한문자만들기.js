const s = "try hello world";

function solution(s) {
  let answer = "";
  let idx = 0;
  for (let i = 0; i < s.length; i++, idx++) {
    if (s[i] === " ") {
      idx = -1;
      answer += " ";
    }
    if (idx % 2 === 0) {
      answer += s[i].toUpperCase();
    } else {
      answer += s[i].toLowerCase();
    }
  }
  return answer;
}

console.log(solution(s));
