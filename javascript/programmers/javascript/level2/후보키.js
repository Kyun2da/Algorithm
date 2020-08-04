const relation = [
  ["100", "ryan", "music", "2"],
  ["200", "apeach", "math", "2"],
  ["300", "tube", "computer", "3"],
  ["400", "con", "computer", "4"],
  ["500", "muzi", "music", "3"],
  ["600", "apeach", "music", "2"],
];

const solution = (relation) => {
  const cols = relation[0].length;
  const rows = relation.length;
  const sets = 1 << cols; //조합의 경우의 수,cols 만큼 비트 이동 ex) col 이 4 이면 16
  const sk = new Set();

  for (let i = 1; i < sets; i++) {
    //공집합은 빼니까 1부터
    const tmp = new Set();
    for (let row = 0; row < rows; row++) {
      let key = "";
      for (let col = 0; col < cols; col++) {
        if (i & (1 << col)) key = String(key) + String(relation[row][col]);
      }
      tmp.add(key);
    }
    if (tmp.size === rows) sk.add(i); //set으로 모든 rows 가 중복이 아니면 유일성을 만족
    console.log(tmp);
  }
  console.log(sk);
  for (let i of sk) {
    for (let j of sk) {
      if (i >= j) continue;
      if ((i & j) === i) sk.delete(j);
    }
  }
  console.log(sk);
  console.log(Array.from(sk).map((e) => e.toString(2)));

  return sk.size;
};

console.log(solution(relation));
