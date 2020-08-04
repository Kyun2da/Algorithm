const n = 5;
const results = [
  [4, 3],
  [4, 2],
  [3, 2],
  [1, 2],
  [2, 5],
];

const solution = (n, results) => {
  let boxers = new Array(n).fill(0);
  boxers = boxers.map((a) => [[], []]);
  // 각 선수간 이기고 진 결과를 담는다.
  for (let i = 0; i < results.length; i++) {
    let result = results[i];
    // 각 번호의 1번 자리에는 각 번호 자신이 이긴 선수들을 추가
    // 각 번호의 0번 자리에는 각 번호 자신이 진 선수를 추가
    boxers[result[0] - 1][1].push(result[1]);
    boxers[result[1] - 1][0].push(result[0]);
  }

  //console.log(boxers);
  let idx = 0;
  //  각 선수별 경기 결과가 상호 결과에 주는 영향을 파악 하기
  while (idx < n) {
    for (let i = 0; i < results.length; i++) {
      let result = results[i];
      let r1 = result[0];
      let r2 = result[1];
      for (let j = 0; j < boxers.length; j++) {
        let boxer = boxers[j];
        // 지는 리스트
        let b1 = boxer[0];
        // 이기는 리스트
        let b2 = boxer[1];
        // 이미 모든 선수와의 관계가 결정 되어 있으면 무시
        if (b1.length + b2.length == n - 1) continue;
        //특정 선수가 r2에는 지는데  r1한테는 지는게 기록 되어 있지 않으면 그 선수는 반드시 r1에게 져야 한다. 왜냐면 r2는 r1에게 지기 때문이다.
        if (b1.includes(r2)) {
          if (!b1.includes(r1)) b1.push(r1);
        }
        // 특정 선수가 r1에게는 이기는데 r2한테 이기는게 기록되어 있지 안흥면 그 선수는  반드시 r2에게 이긴다. r1은  r2에게 이기기 때문이다
        if (b2.includes(r1)) {
          if (!b2.includes(r2)) b2.push(r2);
        }
      }
    }
    idx++;
  }
  //console.log(boxers);
  return boxers.filter((a) => {
    return a[0].length + a[1].length == n - 1 ? true : false;
  }).length;
};

console.log(solution(n, results));
