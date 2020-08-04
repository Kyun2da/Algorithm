const n = 2;
const words = ["qwe", "eqwe", "eqwe"];

//탈락하는 경우는 1. 맨뒷글자를 안맞추고 말했을 때, 2. 앞에 말했던 단어를 또 말했을때
function solution(n, words) {
  var answer = [0, 0];
  for (let i = 1; i < words.length; i++) {
    // console.log(
    //   words[i - 1].split("").splice(-1),
    //   words[i].split("").splice(0, 1)
    // );
    if (
      words[i - 1].split("").splice(-1)[0] !==
        words[i].split("").splice(0, 1)[0] ||
      words.slice(0, i).indexOf(words[i]) !== -1
    ) {
      answer[0] = (i % n) + 1;
      answer[1] = Math.ceil((i + 1) / n);
      return answer;
    }
  }
  return answer;
}

console.log(solution(n, words));
