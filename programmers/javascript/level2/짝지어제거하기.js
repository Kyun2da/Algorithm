const s = "baabaa";

const solution = (s) => {
  const stack = [];

  for (let i = 0; i < s.length; i++) {
    if (stack.length === 0 || stack[stack.length - 1] !== s[i]) {
      stack.push(s[i]);
    } else {
      stack.pop();
    }
  }

  if (stack.length === 0) {
    return 1;
  }
  return 0;
};

console.log(solution(s));

// 효율성 통과 못한 코드
/*
const solution = (s) => {
    let answer = 0;
    for (let i = 0; i < s.length - 1; i++) {
      if (s[i] === s[i + 1]) {
        s = s.substr(0, i) + s.substr(i + 2);
        i -= 2;
      }
      console.log(s);
    }
    if (s === "") {
      return 1;
    }
    return 0;
  };
  
  console.log(solution(s));
  */
