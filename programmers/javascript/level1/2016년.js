const a = 5;
const b = 24;

function solution(a, b) {
  const days = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
  const DayOfWeek = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
  let answer = "";
  let cal_days = 0;
  for (let i = 0; i < a - 1; i++) {
    cal_days += days[i];
  }
  cal_days += b;
  answer = DayOfWeek[(cal_days + 4) % 7];
  return answer;
}

console.log(solution(a, b));
