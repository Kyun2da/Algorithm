const record = [
  "Enter uid1234 Muzi",
  "Enter uid4567 Prodo",
  "Leave uid1234",
  "Enter uid1234 Prodo",
  "Change uid4567 Ryan",
];

const solution = (record) => {
  let answer = [];

  let newArr = record.map((str) => str.split(" "));

  //최종 닉네임으로 변경
  let nickNameSet = {};
  for (let i = 0; i < newArr.length; i++) {
    if (newArr[i][0] === "Enter" || newArr[i][0] === "Change") {
      nickNameSet[newArr[i][1]] = newArr[i][2];
    }
  }

  //출력
  for (let i = 0; i < newArr.length; i++) {
    if (newArr[i][0] === "Enter") {
      answer.push(nickNameSet[newArr[i][1]] + "님이 들어왔습니다.");
    } else if (newArr[i][0] === "Leave") {
      answer.push(nickNameSet[newArr[i][1]] + "님이 나갔습니다.");
    }
  }
  return answer;
};

console.log(solution(record));
