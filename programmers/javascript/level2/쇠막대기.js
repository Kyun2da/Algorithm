const arrangement = "()(((()())(())()))(())";

const solution = (arrangement) => {
  let answer = 0;
  let stack = 0;
  for (let i = 0; i < arrangement.length; i++) {
    if (arrangement[i] === "(") {
      if (arrangement[i + 1] === "(") {
        answer += 1;
        stack += 1;
      } else {
        answer += stack;
        i++;
      }
    } else {
      stack -= 1;
    }
  }
  return answer;
};

console.log(solution(arrangement));
