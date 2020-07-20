const budgets = [100, 120, 100, 120, 150];
const M = 400;

const solution = (budgets, M) => {
  let answer = 0;
  const sum = budgets.reduce((acc, cur) => {
    return acc + cur;
  }, 0);
  //console.log(budgets);
  if (sum <= M) {
    let max = 0;
    for (let i = 0; i < budgets.length; i++) {
      if (budgets[i] > max) {
        max = budgets[i];
      }
    }
    return max;
  } else {
    let min = 0;
    let max = M;
    while (true) {
      let num = Math.floor((max + min) / 2);
      if (answer === num) return answer;
      const calculateBudget = budgets.reduce((acc, cur) => {
        if (cur > num) {
          return acc + num;
        } else {
          return acc + cur;
        }
      }, 0);
      if (calculateBudget === M) return num;
      else if (calculateBudget < M) {
        min = num;
        answer = num;
      } else {
        max = num;
        answer = num;
      }
    }
  }
};

console.log(solution(budgets, M));
