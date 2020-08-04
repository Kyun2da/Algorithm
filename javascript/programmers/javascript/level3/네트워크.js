const n = 3;
const computers = [
  [1, 1, 0],
  [1, 1, 0],
  [0, 0, 1],
];

const dfs = (idx, arr, computers) => {
  //console.log(idx);
  arr[idx] = true;
  for (let i = 0; i < computers.length; i++) {
    if (computers[idx][i] === 1 && !arr[i]) {
      dfs(i, arr, computers);
    }
  }
};

const solution = (n, computers) => {
  let answer = 0;
  const arr = new Array(n).fill(false);
  //console.log(arr);

  while (arr.findIndex((e) => e === false) !== -1) {
    dfs(
      arr.findIndex((e) => e === false),
      arr,
      computers
    );
    answer++;
  }
  return answer;
};

console.log(solution(n, computers));
