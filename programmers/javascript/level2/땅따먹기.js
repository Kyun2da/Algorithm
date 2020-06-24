const land = [
  [1, 2, 3, 5],
  [5, 6, 7, 8],
  [4, 3, 2, 1],
];

const solution = (land) => {
  let answer = 0;
  for (let i = 1; i < land.length; i++) {
    for (let j = 0; j < land[i].length; j++) {
      let maxNum = 0;
      for (let k = 0; k < land[i].length; k++) {
        if (j === k) {
          //비교하고자 하는 열이 같을땐 Continue
          continue;
        }
        if (maxNum < land[i][j] + land[i - 1][k]) {
          maxNum = land[i][j] + land[i - 1][k];
        }
      }
      land[i][j] = maxNum;
    }
  }
  for (let i = 0; i < 4; i++) {
    if (answer < land[land.length - 1][i]) {
      answer = land[land.length - 1][i];
    }
  }
  return answer;
};

console.log(solution(land));
