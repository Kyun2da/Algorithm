const dartResult = "1D2S3T*";

function solution(dartResult) {
  let score_arr = [];
  let SDT_arr = [];
  let prize_arr = ["", "", ""];
  let idx = -1;
  for (let i = 0; i < dartResult.length; i++) {
    if (dartResult[i] >= "0" && dartResult[i] <= "9") {
      if (dartResult[i + 1] == "0") {
        score_arr.push(10);
        i++;
      } else {
        score_arr.push(parseInt(dartResult[i]));
      }
      idx++;
    } else if (
      dartResult[i] === "S" ||
      dartResult[i] === "D" ||
      dartResult[i] === "T"
    ) {
      SDT_arr.push(dartResult[i]);
    } else {
      prize_arr[idx] = dartResult[i];
    }
  }
  var answer = 0;
  for (let i = 0; i < 3; i++) {
    if (SDT_arr[i] === "S") {
      score_arr[i] = Math.pow(score_arr[i], 1);
    } else if (SDT_arr[i] === "D") {
      score_arr[i] = Math.pow(score_arr[i], 2);
    } else {
      score_arr[i] = Math.pow(score_arr[i], 3);
    }

    if (prize_arr[i] === "*") {
      for (let j = i - 1; j <= i; j++) {
        score_arr[j] *= 2;
      }
    } else if (prize_arr[i] === "#") {
      score_arr[i] *= -1;
    }
  }
  //   console.log(score_arr);
  //   console.log(SDT_arr);
  //   console.log(prize_arr);
  const reducer = (accumulator, currentValue) => accumulator + currentValue;
  answer = score_arr.reduce(reducer);
  return answer;
}

console.log(solution(dartResult));
