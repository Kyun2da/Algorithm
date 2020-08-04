const number = "4177252841";
const k = 4;

const solution = (number, k) => {
  const stack = [];
  for (let i = 0; i < number.length; i++) {
    let now = number[i];
    while (k > 0 && stack[stack.length - 1] < now) {
      stack.pop();
      k--;
    }
    stack.push(now);
  }
  stack.splice(stack.length - k, k);
  let answer = stack.join("");

  return answer;
};

console.log(solution(number, k));
