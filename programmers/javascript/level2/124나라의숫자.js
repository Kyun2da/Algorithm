const n = 4;

const solution = (n) => {
  var answer = "";
  while (n !== 0) {
    if (n % 3 === 0) {
      answer = "4" + answer;
      n = parseInt(n / 3) - 1;
    } else {
      answer = String(n % 3) + answer;
      n = parseInt(n / 3);
    }
  }
  return answer;
};

console.log(solution(n));
