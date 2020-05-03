const s = "AB";
const n = 1;

function solution(s, n) {
  let result = "";
  for (let i = 0; i < s.length; i++) {
    if (s[i] == " ") result += " ";
    else
      result += String.fromCharCode(
        s.charCodeAt(i) > 90
          ? ((s.charCodeAt(i) + n - 97) % 26) + 97
          : ((s.charCodeAt(i) + n - 65) % 26) + 65
      );
  }
  return result;
}

console.log(solution(s, n));
