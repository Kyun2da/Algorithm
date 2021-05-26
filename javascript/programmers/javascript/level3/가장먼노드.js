const n = 6;
const edge = [
  [3, 6],
  [4, 3],
  [3, 2],
  [1, 3],
  [1, 2],
  [2, 4],
  [5, 2],
];

const solution = (n, edge) => {
  const visited = new Array(n + 1).fill(-1);
  const queue = [1];
  const adjList = new Array(n + 1).fill(null).map(() => Array());
  visited[0] = 0;
  visited[1] = 0;
  for (let i of edge) {
    adjList[i[0]].push(i[1]);
    adjList[i[1]].push(i[0]);
  }
  //모든 노드를 방문할때까지 계속한다.
  while (queue.length > 0) {
    //방문한 노드를 큐에서 뺀다.
    const node = queue.shift();
    //edge를 순회하며 다음 방문할 노드를 찾는다.
    //방문할 노드가 있다면
    if (adjList[node]) {
      adjList[node].forEach((n) => {
        //이미 방문했던 노드라면 엣지를 그냥 skip한다.
        if (visited[n] === -1) {
          //방문하지 않았던 노드라면 노드를 방문해준다.
          queue.push(n);
          visited[n] = visited[node] + 1;
        }
      });
    }
  }
  console.log(visited);
  const maxNum = Math.max(...visited);
  return visited.filter((e) => e === maxNum).length;
};

console.log(solution(n, edge));
