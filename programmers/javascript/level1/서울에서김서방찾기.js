const seoul = ["Kim", "Kimgoon"];

function solution(seoul) {
  let idx = seoul.indexOf("Kim", 0);
  var answer = `김서방은 ${idx}에 있다`;
  return answer;
}

console.log(solution(seoul));
