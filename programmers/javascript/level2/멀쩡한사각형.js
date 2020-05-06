function gcd(a, b) {
  while (b > 0) {
    let temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

function solution(w, h) {
  let answer = w * h;
  answer -= w + h - gcd(w, h);
  return answer;
}
