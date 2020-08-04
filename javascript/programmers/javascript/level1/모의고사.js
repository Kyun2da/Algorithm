//const answers = [1, 2, 3, 4, 5];
const answers = [1, 3, 2, 4, 2];

function solution(answers) {
  var answer = [];
  let one = [];
  let two = [];
  let three = [];
  let answer1 = 0;
  let answer2 = 0;
  let answer3 = 0;
  let max = 0;
  const arr = [2, 1, 2, 3, 2, 4, 2, 5];
  const arr2 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
  for (let i = 0; i < answers.length; i++) {
    one.push((i % 5) + 1);
    two.push(arr[i % 8]);
    three.push(arr2[i % 10]);
    if (one[i] === answers[i]) {
      answer1++;
    }
    if (two[i] === answers[i]) {
      answer2++;
    }
    if (three[i] === answers[i]) {
      answer3++;
    }
  }
  max = Math.max(answer1, answer2, answer3);
  if (max === answer1) {
    answer.push(1);
  }
  if (max === answer2) {
    answer.push(2);
  }
  if (max === answer3) {
    answer.push(3);
  }
  return answer;
}

console.log(solution(answers));

//filter를 사용한 좀더 간단한 풀이
function solution2(answers) {
  let answer = [];
  let a1 = [1, 2, 3, 4, 5];
  var a2 = [2, 1, 2, 3, 2, 4, 2, 5];
  var a3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];

  let answer1 = answers.filter((a, i) => a === a1[i % a1.length]).length;
  let answer2 = answers.filter((a, i) => a === a2[i % a2.length]).length;
  let answer3 = answers.filter((a, i) => a === a3[i % a3.length]).length;
  let max = Math.max(answer1, answer2, answer3);
  if (max === answer1) {
    answer.push(1);
  }
  if (max === answer2) {
    answer.push(2);
  }
  if (max === answer3) {
    answer.push(3);
  }

  return answer;
}

console.log(solution2(answers));
