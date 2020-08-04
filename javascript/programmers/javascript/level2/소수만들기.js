const num = [1, 2, 3, 4];

function solution(nums) {
  let answer = 0;
  let arr = new Array();
  for (let i = 0; i <= 3000; i++) {
    arr[i] = 1; //소수가 아닌걸로 초기화
  }
  for (let i = 2; i <= Math.sqrt(3000); i++) {
    if (arr[i] === 0) continue;
    for (let j = i + i; j <= 3000; j += i) {
      arr[j] = 0;
    }
  }
  for (let i = 0; i < nums.length - 2; i++) {
    for (let j = i + 1; j < nums.length - 1; j++) {
      for (let k = j + 1; k < nums.length; k++) {
        if (arr[nums[i] + nums[j] + nums[k]] === 1) answer++;
      }
    }
  }

  return answer;
}

console.log(solution(num));
