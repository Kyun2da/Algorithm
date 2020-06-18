const numbers = "17";

let nums = new Set();
let answer = 0;
const chkPrime = (num) => {
  if (num < 2) return false;
  if (num === 2) return true;
  for (let i = 2; i <= Math.sqrt(num); i++) {
    if (num % i === 0) return false;
  }
  return true;
};

const permutation = (a, s) => {
  if (s.length > 0) {
    if (!nums.has(Number(s))) {
      nums.add(Number(s));
      if (chkPrime(Number(s))) {
        answer++;
      }
    }
  }
  if (a.length > 0) {
    for (let i = 0; i < a.length; i++) {
      let t = a.slice(0);
      t.splice(i, 1);
      permutation(t, s + a[i]);
    }
  }
};

function solution(numbers) {
  let n = numbers.split("");
  permutation(n, "");
  return answer;
}

console.log(solution(numbers));
