const n = 4;
const costs = [
  [0, 1, 1],
  [0, 2, 2],
  [2, 3, 1],
];

const solution = (n, costs) => {
  let answer = 0;
  const isVisited = new Array(n).fill(false);
  const isBridge = new Array(costs.length).fill(false);
  costs.sort((a, b) => {
    return a[2] - b[2];
  });
  let num = 0;

  isVisited[costs[0][0]] = true;
  isVisited[costs[0][1]] = true;
  isBridge[0] = true;
  answer += costs[0][2];
  num += 1;

  while (num < n - 1) {
    for (let i = 1; i < costs.length; i++) {
      const [start, end, cost] = costs[i];
      if (
        !isBridge[i] &&
        ((!isVisited[start] && isVisited[end]) ||
          (isVisited[start] && !isVisited[end]))
      ) {
        num++;
        answer += cost;
        isVisited[start] = true;
        isVisited[end] = true;
        isBridge[i] = true;
        break;
      }
      console.log(isVisited);
    }
  }
  return answer;
};

console.log(solution(n, costs));
