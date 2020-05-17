const n = 5;

function solution(n) {
  var ans = 0;
  while (n != 0) {
    // 0 될때까지 반복

    if (n % 2 == 0) {
      // 2로 나눠지면 나눈다
      n = n / 2;
    } else {
      n = n - 1; // 나눠지지 않을 경우 1을 빼본다
      ans++; // 배터리 소모
    }
  }
  return ans;
}

console.log(solution(n));
