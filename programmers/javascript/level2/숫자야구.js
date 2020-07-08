const baseball = [
  [123, 1, 1],
  [356, 1, 0],
  [327, 2, 0],
  [489, 0, 1],
];

const solution = (baseball) => {
  let answer = 0;
  const arr = new Array(1000);

  //서로다른 자리의 수를 가진 수만 답이될수 있도록 표시
  for (let i = 123; i < 1000; i++) {
    const str = String(i);
    if (str[0] == str[1] || str[1] == str[2] || str[0] == str[2]) {
      arr[i] = 0;
    } else if (str[1] == "0" || str[2] == "0") {
      arr[i] = 0;
    } else {
      arr[i] = 1;
    }
  }

  for (let i = 0; i < baseball.length; i++) {
    const arrStr = String(baseball[i][0]);
    for (let j = 123; j < 1000; j++) {
      if (arr[j] === 0) {
        continue;
      }

      const str = String(j);
      let strike = 0;
      let ball = 0;
      for (let k = 0; k < 3; k++) {
        for (let m = 0; m < 3; m++) {
          if (str[k] == arrStr[m]) {
            if (k === m) {
              strike++;
            } else {
              ball++;
            }
            break;
          }
        }
      }
      if (strike !== baseball[i][1] || ball !== baseball[i][2]) {
        arr[j] = 0;
      }
    }
  }
  for (let i = 123; i < 1000; i++) {
    if (arr[i] === 1) {
      answer++;
    }
  }
  return answer;
};

console.log(solution(baseball));
