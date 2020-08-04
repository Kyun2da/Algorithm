const brown = 24;
const yellow = 24;

const solution = (brown, yellow) => {
  const answer = [];
  for (let i = 1; i <= yellow; i++) {
    if (yellow % i !== 0) {
      continue;
    }
    //console.log(i);
    if ((yellow / i) * 2 + i * 2 === brown - 4) {
      answer.push(yellow / i + 2, i + 2);
      break;
    }
  }
  return answer;
};

console.log(solution(brown, yellow));
