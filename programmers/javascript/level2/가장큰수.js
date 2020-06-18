const numbers = [0, 0, 0, 0, 0];

const compare = (a, b) => {
  return b + a - (a + b);
};

const solution = (numbers) => {
  var answer = "";
  answer = numbers.map(String).sort(compare).join("");
  if (answer[0] === "0") {
    answer = "0";
  }
  return answer;
};

console.log(solution(numbers));
