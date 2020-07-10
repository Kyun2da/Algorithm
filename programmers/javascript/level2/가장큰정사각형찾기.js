const board = [
  [1, 0],
  [0, 0],
];
const solution = (board) => {
  let answer = 0;

  answer = board[0].indexOf(1) != -1 ? 1 : 0;
  for (let i = 0; i < board.length; i++) {
    if (board[i][0] === 1) {
      answer = 1;
      break;
    }
  }

  for (let j = 1; j < board.length; j++) {
    for (let i = 1; i < board[0].length; i++) {
      if (board[j][i] === 1) {
        board[j][i] =
          Math.min(board[j - 1][i], board[j][i - 1], board[j - 1][i - 1]) + 1;
      }
      if (board[j][i] > answer) {
        answer = board[j][i];
      }
    }
  }
  return answer * answer;
};

console.log(solution(board));
