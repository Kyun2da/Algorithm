const s = "3people unFollowed me";

const changeJadenWord = (s) => {
  let s1 = s.substring(0, 1);
  let s2 = s.substring(1);
  if (
    s1.charCodeAt() >= "a".charCodeAt() &&
    s1.charCodeAt() <= "z".charCodeAt()
  ) {
    s1 = s1.toUpperCase();
  }
  s2 = s2.toLowerCase();
  return s1 + s2;
};

const solution = (s) => {
  let arr = s.split(" ");
  for (let i = 0; i < arr.length; i++) {
    arr[i] = changeJadenWord(arr[i]);
  }
  arr = arr.join(" ");
  return arr;
};

console.log(solution(s));

//////////////////////다른 풀이
const solution = (s) => {
  let answer = "";
  for (let i = 0; i < s.length; i++) {
    if (i === 0 || s[i - 1] === " ") {
      answer += s[i].toUpperCase();
    } else {
      answer += s[i].toLowerCase();
    }
  }
  return answer;
};
