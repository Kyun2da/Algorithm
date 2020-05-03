const n = 3;
const m = 12;

function gcd(a, b) {
  while (b > 0) {
    let temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

function lcm(a, b) {
  return (a * b) / gcd(a, b);
}

function solution(n, m) {
  var answer = [];
  answer.push(gcd(n, m));
  answer.push(lcm(n, m));
  return answer;
}

console.log(solution(n, m));
