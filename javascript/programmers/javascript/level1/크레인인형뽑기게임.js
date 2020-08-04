let board = [
  [0, 0, 0, 0, 0],
  [0, 0, 1, 0, 3],
  [0, 2, 5, 0, 1],
  [4, 2, 4, 4, 2],
  [3, 5, 1, 3, 1],
];
let moves = [1, 5, 3, 5, 1, 2, 1, 4];
var answer = 0;

function solution(board, moves) {
  let bucket = [];
  for (let i = 0; i < moves.length; i++) {
    for (let j = 0; j < board.length; j++) {
      if (board[j][moves[i] - 1] !== 0) {
        if (bucket[bucket.length - 1] === board[j][moves[i] - 1]) {
          answer += 2;
          bucket.pop();
        } else {
          bucket.push(board[j][moves[i] - 1]);
        }
        console.log(bucket);
        board[j][moves[i] - 1] = 0;
        break;
      }
    }
  }
  return answer;
}

solution(board, moves);
console.log(answer);
