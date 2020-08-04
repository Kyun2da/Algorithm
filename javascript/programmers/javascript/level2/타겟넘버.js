const numbers = [1, 1, 1, 1, 1];
const target = 3;

let answer = 0;
const dfs = (numbers, target, idx, plusMinus, sum) => {
  if (idx === numbers.length) {
    if (target === sum) {
      answer += 1;
    }
    return;
  } else {
    let tmp = sum + numbers[idx] * plusMinus;
    dfs(numbers, target, idx + 1, 1, tmp);
    dfs(numbers, target, idx + 1, -1, tmp);
  }
};

const solution = (numbers, target) => {
  dfs(numbers, target, 0, 1, 0);
  dfs(numbers, target, 0, -1, 0);
  return answer / 2;
};

console.log(solution(numbers, target));

//다른 사람 풀이
/*
function solution(numbers, target) {
    let answer = 0;
    getAnswer(0,0);
    function getAnswer(x,value) {
        if(x<numbers.length){
            getAnswer(x+1,value + numbers[x]);
            getAnswer(x+1,value - numbers[x]);
        } else{
            if(value === target){
                answer++
            }
        }
    }
    return answer;
}
*/
