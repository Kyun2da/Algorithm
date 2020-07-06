const citations = [3, 0, 6, 1, 5];

const solution = (citations) => {
  let answer = 0;
  let arr = new Array(10001);
  for (let i = 0; i < arr.length; i++) {
    arr[i] = 0;
  }

  for (let i = 0; i < citations.length; i++) {
    arr[citations[i]] += 1;
  }
  for (let i = 9999; i >= 0; i--) {
    arr[i] += arr[i + 1];
  }

  for (let i = 10000; i >= 0; i--) {
    if (arr[i] >= i) {
      return i;
    }
  }
};

console.log(solution(citations));

//다른사람 풀이

const sorting = (a, b) => {
  return b - a;
};

const solution2 = (citations) => {
  citations = citations.sort(sorting);
  let i = 0;
  while (i + 1 <= citations[i]) {
    i++;
  }
  return i;
};

console.log(solution2(citations));
