const triangle = [[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]];

const solution = (triangle) => {
  let answer = 0;
  const col = triangle.length;
  for (let i = 1; i < col; i++) {
    for (let j = 0; j < triangle[i].length; j++) {
      if (j === 0) {
        triangle[i][j] += triangle[i - 1][j];
      } else if (j === triangle[i].length - 1) {
        triangle[i][j] += triangle[i - 1][j - 1];
      } else {
        triangle[i][j] += Math.max(triangle[i - 1][j - 1], triangle[i - 1][j]);
      }
    }
  }
  for (let i = 0; i < triangle[col - 1].length; i++) {
    if (answer < triangle[col - 1][i]) {
      answer = triangle[col - 1][i];
    }
  }

  return answer;
};

console.log(solution(triangle));
