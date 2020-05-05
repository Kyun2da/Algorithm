const N = 5;
const stages = [2, 1, 2, 6, 2, 4, 3, 3];

// 객체 이용
function solution(N, stages) {
  var answer = [];
  for (let i = 1; i <= N; i++) {
    let top = stages.filter((val) => val === i).length;
    let bottom = stages.filter((val) => val >= i).length;
    if (bottom === 0) {
      answer.push({ stageNumber: i, failRate: 0 });
    } else {
      answer.push({ stageNumber: i, failRate: top / bottom });
    }
  }

  return answer
    .sort((a, b) =>
      b.failRate === a.failRate
        ? a.stageNumber - b.stageNumber
        : b.failRate - a.failRate
    )
    .map((el) => el.stageNumber);
}

console.log(solution(N, stages));
