const arr1 = [
  [1, 2],
  [2, 3],
];
const arr2 = [
  [3, 4],
  [5, 6],
];

function solution(arr1, arr2) {
  return arr1.map((arr, i) => arr.map((v, j) => v + arr2[i][j]));
}

console.log(solution(arr1, arr2));
