const a = 3;
const b = 5;

function solution(a, b) {
  let answer = 0;
  if (a > b) {
    let tmp = a;
    a = b;
    b = tmp;
  }
  answer = ((b + 1) * b - (a - 1) * a) / 2;
  return answer;
}

console.log(solution(a, b));
