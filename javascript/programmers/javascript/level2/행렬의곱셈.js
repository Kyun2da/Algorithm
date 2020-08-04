const arr1 = [
  [2, 3, 2],
  [4, 2, 4],
  [3, 1, 4],
];
const arr2 = [
  [5, 4, 3],
  [2, 4, 1],
  [3, 1, 1],
];

const solution = (arr1, arr2) => {
  var answer = [];
  for (let i = 0; i < arr1.length; i++) {
    answer.push([]);
    for (let j = 0; j < arr2[0].length; j++) {
      answer[i][j] = 0;
      for (let k = 0; k < arr1[0].length; k++) {
        answer[i][j] += arr1[i][k] * arr2[k][j];
      }
    }
  }
  return answer;
};

console.log(solution(arr1, arr2));
