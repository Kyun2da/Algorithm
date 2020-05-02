//const s = "abcde";
const s = "qwer";

function solution(s) {
  let answer = "";
  if (s.length % 2 == 1) {
    answer = s[parseInt(s.length / 2)];
  } else {
    answer = s[parseInt(s.length / 2) - 1] + s[parseInt(s.length / 2)];
  }

  return answer;
}

console.log(solution(s));
