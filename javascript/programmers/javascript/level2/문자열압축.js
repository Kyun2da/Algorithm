const s = "aabbaccc";

const solution = (s) => {
  var answer = s.length;
  for (let i = 1; i <= s.length; i++) {
    //압축할 단어
    let newString = "";
    let count = 1;
    for (let j = 0; j < s.length; j += i) {
      let word = s.substring(j, j + i);
      let nextWord = s.substring(j + i, j + i * 2);
      if (word === nextWord) {
        count++;
      } else {
        if (count === 1) {
          newString = newString + word;
        } else {
          newString = newString + `${count}${word}`;
        }
        count = 1;
      }
    }
    console.log(newString);
    if (newString.length < answer) {
      answer = newString.length;
    }
  }
  return answer;
};

console.log(solution(s));
