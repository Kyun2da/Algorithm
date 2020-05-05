const arr = 12;

function solution(x) {
  var answer = true;
  let temp = x;
  let pos_num = 0;
  while (temp != 0) {
    pos_num += temp % 10;
    temp = parseInt(temp / 10);
  }
  if (Number.isInteger(x / pos_num)) answer = true;
  else answer = false;
  return answer;
}

console.log(solution(arr));
