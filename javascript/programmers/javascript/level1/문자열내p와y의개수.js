const s = "pPoooyY";

function solution(s) {
  var answer = true;
  let p_num = 0;
  let y_num = 0;
  for (let i = 0; i < s.length; i++) {
    if (s[i] === "p" || s[i] === "P") p_num++;
    if (s[i] === "y" || s[i] === "Y") y_num++;
  }
  if (p_num !== y_num) answer = false;
  return answer;
}

console.log(solution(s));
