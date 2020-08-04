const s = "1 2 3 4";

const solution = (s) => {
  const arr = s
    .split(" ")
    .map((it) => parseInt(it))
    .sort((a, b) => a - b);
  return String(arr[0]) + " " + String(arr[arr.length - 1]);
};

console.log(solution(s));
