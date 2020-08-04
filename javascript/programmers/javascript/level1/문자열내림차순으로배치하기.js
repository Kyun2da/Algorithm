const s = "Zbcdefg";

function solution(s) {
  return s.split("").sort().reverse().join("");
}

console.log(solution(s));
