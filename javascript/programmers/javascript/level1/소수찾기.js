const n = 10;

function solution(n) {
  let arr = [0, 0];
  var answer = 0;
  // 입력받은 수 만큼 배열에 모두 초기화 해둔다
  for (let i = 2; i <= n; i++) {
    arr[i] = i;
  }
  for (let i = 2; i <= Math.sqrt(n); i++) {
    if (arr[i] == 0)
      // 이미 체크된 수의 배수는 확인하지 않는다
      continue;
    for (let j = i + i; j <= n; j += i) {
      // i를 제외한 i의 배수들은 0으로 체크
      arr[j] = 0;
    }
  }
  for (let i = 1; i <= n; i++) {
    if (arr[i] !== 0) {
      answer++;
    }
  }
  return answer;
}

console.log(solution(n));
