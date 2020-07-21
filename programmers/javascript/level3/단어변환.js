const begin = "hit";
const target = "cog";
const words = ["hot", "dot", "dog", "lot", "log", "cog"];

let answer = 100;
let check = [];

const diffOneLetters = (begin, words) => {
  let diffNum = 0;
  for (let i = 0; i < begin.length; i++) {
    if (begin[i] !== words[i]) diffNum += 1;
  }
  if (diffNum === 1) return 1;
  return 0;
};

const dfs = (begin, target, words, depth, check) => {
  //시작단어가 타겟단어와 같다면 답은 depth-1이다.
  if (begin == target && answer > depth) {
    answer = depth;
    console.log(check);
    return;
  }
  for (let i = 0; i < words.length; i++) {
    //방문하지 않았고 단어의 차이가 한개라면 방문한다.
    if (!check[i] && diffOneLetters(begin, words[i])) {
      depth += 1;
      check[i] = true;
      dfs(words[i], target, words, depth, check);
      check[i] = false;
      depth -= 1;
    }
  }
};

const solution = (begin, target, words) => {
  if (!words.includes(target)) {
    return 0;
  }
  for (let i = 0; i < words.length; i++) check[i] = false;
  dfs(begin, target, words, 0, check);
  return answer === 100 ? 0 : answer;
};

console.log(solution(begin, target, words));
