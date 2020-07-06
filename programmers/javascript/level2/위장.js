const clothes = [
  ["yellow_hat", "headgear"],
  ["blue_sunglasses", "eyewear"],
  ["green_turban", "headgear"],
];

function solution(clothes) {
  let answer = 1;
  const obj = {};

  //옷을 개수별로 분리 + 1  (안입는 경우가 있으므로 +1을 해줘야한다.)
  for (let i = 0; i < clothes.length; i++) {
    obj[clothes[i][1]] = (obj[clothes[i][1]] || 1) + 1;
  }

  for (let key in obj) {
    answer *= obj[key];
  }
  //console.log(obj);

  //아예 안입는 경우는 빼줘야하므로 -1을 해준다.
  return answer - 1;
}

console.log(solution(clothes));
