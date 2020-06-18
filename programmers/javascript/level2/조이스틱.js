const name = "ABC";

const solution = (name) => {
  let answer = 0;
  let temp = "A".repeat(name.length);
  let idx = 0;
  let direction = 1;
  while (true) {
    if (name[idx].charCodeAt(0) > 78) {
      //조이스틱 위로
      answer += 90 - name[idx].charCodeAt(0) + 1;
    } else {
      //조이스틱 아래로
      answer += name[idx].charCodeAt(0) - 65;
    }
    temp = temp.substring(0, idx) + name[idx] + temp.substring(idx + 1);
    console.log(temp);
    if (temp === name) {
      //답이 완성되면 브레이크
      break;
    }
    //TODO : A가아닐때까지 가는 거리 계산하는 로직 필요
    if (temp[idx] === "A") {
    }
    idx++;
    answer++;
  }

  return answer;
};

console.log(solution(name));
