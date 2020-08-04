const weight = [3, 4, 5];

const solution = (weight) => {
  let answer = 1;
  weight.sort((a, b) => a - b);
  for (let i = 0; i < weight.length; i++) {
    if (answer < weight[i]) break;
    answer += weight[i];
  }
  return answer;
};

console.log(solution(weight));
