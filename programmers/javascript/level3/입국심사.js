const n = 6;
const times = [7, 10];

const solution = (n, times) => {
  let answer = Infinity;

  times.sort((a, b) => {
    return a - b;
  });
  let left = 1;
  let right = times[times.length - 1] * n;

  while (left <= right) {
    let mid = parseInt((left + right) / 2);
    let cnt = 0;
    for (let i = 0; i < times.length; i++) {
      cnt += parseInt(mid / times[i]);
      //console.log(cnt, mid);
      if (cnt >= n) {
        answer = Math.min(answer, mid);
      }
    }
    if (cnt >= n) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return answer;
};

console.log(solution(n, times));
