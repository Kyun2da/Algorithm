const n = 3;

const solution = (n) => {
  const answer = [0];
  for (let i = 2; i <= n; i++) {
    const len = answer.length;
    answer.push(0);
    for (let j = len - 1; j >= 0; j--) {
      if (answer[j] === 1) {
        answer.push(0);
      } else {
        answer.push(1);
      }
    }
  }
  return answer;
};

console.log(solution(n));
