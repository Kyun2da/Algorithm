const n = 5;
arr1 = [9, 20, 28, 18, 11];
arr2 = [30, 1, 21, 17, 28];

function solution(n, arr1, arr2) {
  let answer = [];

  for (let i = 0; i < n; i++) {
    let temp1 = arr1[i].toString(2);
    let temp2 = arr2[i].toString(2);
    if (temp1.length < n) {
      temp1 = "0".repeat(n - temp1.length) + temp1;
    }
    if (temp2.length < n) {
      temp2 = "0".repeat(n - temp2.length) + temp2;
    }
    let value = "";
    for (let i = 0; i < n; i++) {
      if (parseInt(temp1[i]) || parseInt(temp2[i])) {
        value += "#";
      } else {
        value += " ";
      }
    }
    answer.push(value);
  }
  return answer;
}

console.log(solution(n, arr1, arr2));
