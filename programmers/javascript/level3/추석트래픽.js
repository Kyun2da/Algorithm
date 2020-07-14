const lines = [
  "2016-09-15 20:59:57.421 0.351s",
  "2016-09-15 20:59:58.233 1.181s",
  "2016-09-15 20:59:58.299 0.8s",
  "2016-09-15 20:59:58.688 1.041s",
  "2016-09-15 20:59:59.591 1.412s",
  "2016-09-15 21:00:00.464 1.466s",
  "2016-09-15 21:00:00.741 1.581s",
  "2016-09-15 21:00:00.748 2.31s",
  "2016-09-15 21:00:00.966 0.381s",
  "2016-09-15 21:00:02.066 2.62s",
];

const solution = (lines) => {
  let answer = 0;
  const arr = [];
  const logPointArr = [];
  for (let i = 0; i < lines.length; i++) {
    const line = lines[i].split(" ");
    const edSec =
      Number(line[1].substring(0, 2)) * 3600 +
      Number(line[1].substring(3, 5)) * 60 +
      Number(line[1].substring(6, 12));
    const duration = Number(line[2].substring(0, line[2].length - 1));
    const stSec = edSec - duration + 0.001;
    arr.push([stSec, edSec, duration]);
    logPointArr.push(stSec, edSec);
  }

  logPointArr.sort();
  console.log(logPointArr);

  for (let i = 0; i < logPointArr.length; i++) {
    const beginRange = logPointArr[i];
    const endRange = logPointArr[i] + 1;
    let count = 0;
    for (let j = 0; j < arr.length; j++) {
      let stPoint = arr[j][0];
      let edPoint = arr[j][1];

      if (
        (stPoint >= beginRange && stPoint < endRange) ||
        (edPoint >= beginRange && edPoint < endRange) ||
        (stPoint <= beginRange && edPoint >= endRange)
      ) {
        count++;
      }
    }

    if (count > answer) {
      answer = count;
    }
  }
  return answer;
};

console.log(solution(lines));
