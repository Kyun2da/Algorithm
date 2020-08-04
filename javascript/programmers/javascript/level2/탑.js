const question = [6, 9, 5, 7, 4];

const solution = (heights) => {
  let answer = new Array(heights.length);
  const stack = [];
  for (let i = heights.length - 1; i >= 0; i -= 1) {
    while (stack.length !== 0 && stack[stack.length - 1][0] < heights[i]) {
      answer[stack[stack.length - 1][1]] = i + 1;
      stack.pop();
    }
    stack.push([heights[i], i]);
  }
  answer = Array.from(answer, (item) => item || 0);
  return answer;
};

console.log(solution(question));
