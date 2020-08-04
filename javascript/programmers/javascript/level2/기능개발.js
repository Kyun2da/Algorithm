const temp1 = [93, 30, 55];
const temp2 = [1, 30, 5];

const solution = (progresses, speeds) => {
  let temp = [];
  const answer = [];
  temp = progresses.map((it, i) => Math.ceil((100 - it) / speeds[i]));
  let startNum = temp[0];
  let num = 1;
  for (let i = 0; i < temp.length; i += 1) {
    if (startNum >= temp[i + 1] && i !== temp.length - 1) {
      num += 1;
    } else {
      answer.push(num);
      startNum = temp[i + 1];
      num = 1;
    }
  }
  return answer;
};

console.log(solution(temp1, temp2));
