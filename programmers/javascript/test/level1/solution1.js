const arr = [1, 2, 3, 4];

function solution(arr) {
  var answer = 0;
  answer = arr.reduce((a, b) => a + b, 0) / arr.length;
  return answer;
}

console.log(solution(arr));
