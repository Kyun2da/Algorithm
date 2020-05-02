const string = ["sun", "bed", "car"];
const n = 1;

function solution(strings, n) {
  strings.sort((a, b) => {
    if (a[n] === b[n]) return (a > b) - (a < b);
    else return (a[n] > b[n]) - (a[n] < b[n]);
  });
  return strings;
}

console.log(solution(string, n));
