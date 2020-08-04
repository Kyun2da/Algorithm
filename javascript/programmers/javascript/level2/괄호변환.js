const p = "()))((()";

const isCorrectString = (p) => {
  let check = 0;
  for (let i = 0; i < p.length; i++) {
    if (p[i] === "(") {
      check += 1;
    } else {
      check -= 1;
    }
    if (check < 0) {
      return false;
    }
  }
  return true;
};

const findBalanceStringNum = (p) => {
  let check = 0;
  for (let i = 0; i < p.length; i++) {
    if (p[i] === "(") {
      check += 1;
    } else {
      check -= 1;
    }
    if (check === 0) {
      return i;
    }
  }
};

const reverseString = (p) => {
  let answer = "";
  for (let i = 0; i < p.length; i++) {
    if (p[i] === "(") {
      answer += ")";
    } else {
      answer += "(";
    }
  }
  return answer;
};

const Recursive = (p) => {
  if (p === "") {
    return "";
  }
  if (isCorrectString(p)) {
    return p;
  } else {
    const idx = findBalanceStringNum(p);
    let u = p.substring(0, idx + 1);
    let v = p.substring(idx + 1);
    if (isCorrectString(u)) {
      return u + Recursive(v);
    } else {
      let temp = "(" + Recursive(v) + ")";
      let temp2 = reverseString(u.substring(1, u.length - 1));
      return temp + temp2;
    }
  }
};

const solution = (p) => {
  let answer = "";
  answer = Recursive(p);
  return answer;
};

console.log(solution(p));
