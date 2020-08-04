// const n = 5;
// const lost = [2, 4];
// const reserve = [1, 3, 5];

const n = 5;
const lost = [2, 4];
const reserve = [3];

// const n = 3;
// const lost = [3];
// const reserve = [1];

function solution(n, lost, reserve) {
  let answer = 0;
  let arr = [];
  arr[0] = 0;
  for (let i = 1; i <= n; i++) {
    arr[i] = 1; //한벌씩 있다고 하자
  }
  arr[n + 1] = 0;
  for (let i = 0; i < lost.length; i++) {
    arr[lost[i]] -= 1; //잃어버린 애들 빼준다
  }
  for (let i = 0; i < reserve.length; i++) {
    arr[reserve[i]] += 1; //여벌있는 애들 더해준다.
  }

  //0인애들 중에 양쪽에 2개인애들을 찾아 1로 만들어준다
  for (let i = 1; i <= n; i++) {
    if (arr[i] === 0) {
      if (arr[i - 1] === 2) {
        arr[i - 1] = 1;
        arr[i] = 1;
      } else if (arr[i + 1] === 2) {
        arr[i + 1] = 1;
        arr[i] = 1;
      }
    }
  }
  answer = arr.filter((a) => a >= 1).length;
  return answer;
}

console.log(solution(n, lost, reserve));
