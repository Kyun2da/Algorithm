let phone_number = "01033334444";

function solution(phone_number) {
  let answer = "";
  for (let i = 0; i < phone_number.length - 4; i++) {
    answer += "*";
  }
  answer += phone_number.substring(phone_number.length - 4);
  return answer;
}

console.log(solution(phone_number));
