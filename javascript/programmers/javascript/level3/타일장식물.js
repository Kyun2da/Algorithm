const N = 5;

const solution = (N) => {
  const arr = [4, 6];
  for (let i = 2; i <= N - 1; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  return arr[N - 1];
};

console.log(solution(N));
