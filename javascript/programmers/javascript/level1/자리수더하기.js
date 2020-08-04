const n = 123;

function solution(n) {
  let temp = String(n);
  let answer = 0;

  for (let i = 0; i < temp.length; i++) {
    answer += parseInt(temp[i]);
  }

  return answer;
}

console.log(solution(n));
