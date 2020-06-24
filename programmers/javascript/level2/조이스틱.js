function solution(name) {
  const start = `A`.charCodeAt();
  const end = `Z`.charCodeAt() + 1;
  const strs = name.split(``);
  let answer = 0;
  let i = 0;

  while (true) {
    if (strs[i] !== `A`) {
      const cur = strs[i].charCodeAt();
      const down = Math.abs(start - cur);
      const up = Math.abs(end - cur);

      answer += Math.min(down, up);
      strs[i] = `A`;
    }
    // 알파벳 이름을 완성하였을 때는 커서를 이동할 필요가 없음
    if (strs.findIndex((str) => str !== `A`) === -1) {
      break;
    }
    let rightCount = 0;
    let rightIndex = 0;
    let leftCount = 0;
    let leftIndex = 0;

    // 오른 쪽 카운트
    for (let right = 1; right < strs.length; right++) {
      rightIndex = (i + right) % strs.length;
      if (strs[rightIndex] !== `A`) {
        rightCount = right;
        break;
      }
    }
    // 왼 쪽 카운트
    for (let left = 1; left < strs.length; left++) {
      leftIndex = i - left < 0 ? i - left + strs.length : i - left;
      if (strs[leftIndex] !== `A`) {
        leftCount = left;
        break;
      }
    }
    // 더 가까운 쪽으로 이동
    if (rightCount <= leftCount) {
      i = rightIndex;
      answer += rightCount;
    } else {
      i = leftIndex;
      answer += leftCount;
    }
  }
  return answer;
}
