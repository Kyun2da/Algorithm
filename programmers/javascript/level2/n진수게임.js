const n = 16;
const t = 16;
const m = 2;
const p = 2;

const solution = (n, t, m, p) => {
  let answer = "";
  let str = "";
  let i = 0;
  while (str.length <= t * m) {
    const baseStr = i.toString(n);
    str += baseStr;
    i++;
  }
  for (let i = 0; i < str.length; i++) {
    if (answer.length === t) break;
    if ((i + 1) % m === p || ((i + 1) % m === 0 && m === p)) {
      answer += str[i];
    }
  }
  return answer.toUpperCase();
};

console.log(solution(n, t, m, p));
