const s = "()()";

const solution = (s) => {
  let answer = true;

  let sum = 0;
  for (let i = 0; i < s.length; i++) {
    if (s[i] === "(") {
      sum++;
    } else {
      sum--;
    }
    if (sum < 0) {
      return false;
    }
  }
  if (sum !== 0) {
    return false;
  }
  return true;
};
