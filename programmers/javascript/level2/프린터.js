const priorities = [1, 1, 9, 1, 1, 1];
const location = 0;

function solution(priorities, location) {
  var answer = 0;
  var arr = [];
  for (let i = 0; i < priorities.length; i++) {
    arr.push([priorities[i], i]);
  }
  while (true) {
    let max_num = 0;
    for (let i = 0; i < arr.length; i++) {
      if (max_num < arr[i][0]) {
        max_num = arr[i][0];
      }
    }
    if (max_num === arr[0][0]) {
      answer++;
      if (location === arr[0][1]) return answer;
      arr.splice(0, 1);
    } else {
      let temp = arr[0];
      arr.splice(0, 1);
      arr.push(temp);
    }
  }
}

console.log(solution(priorities, location));
