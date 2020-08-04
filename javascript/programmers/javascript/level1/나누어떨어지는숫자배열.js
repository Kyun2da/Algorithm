// const arr = [5, 9, 7, 10];
// const divisor = 5;
const arr = [2, 36, 1, 3];
const divisor = 1;

function solution(arr, divisor) {
  arr = arr.filter((val) => val % divisor === 0);
  arr.sort((a, b) => {
    return a - b;
  });
  if (arr.length === 0) {
    arr.push(-1);
  }
  return arr;
}

console.log(solution(arr, divisor));
