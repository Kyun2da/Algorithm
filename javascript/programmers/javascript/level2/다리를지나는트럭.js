const val1 = 100;
const val2 = 100;
const val3 = [10, 10, 10, 10, 10, 10, 10, 10, 10, 10];

const sumValue = (arr) => {
  let sum = 0;
  for (let i = 0; i < arr.length; i += 1) {
    sum += arr[i][0];
  }
  return sum;
};

const solution = (bridgeLength, weight, truckWeights) => {
  let answer = 0;
  let temp = [];
  while (truckWeights.length !== 0 || temp.length !== 0) {
    answer += 1;
    if (
      temp.length === 0 ||
      (sumValue(temp) + truckWeights[0] <= weight &&
        temp.length <= bridgeLength)
    ) {
      temp.unshift([truckWeights[0], 0]);
      truckWeights.shift();
    }
    for (let i = 0; i < temp.length; i += 1) {
      temp[i][1] += 1;
    }
    temp = temp.filter((it) => it[1] < bridgeLength);
  }
  answer += 1;
  return answer;
};

console.log(solution(val1, val2, val3));
