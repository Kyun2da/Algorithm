const people = [70, 50, 80, 50];
const limit = 100;

const solution = (people, limit) => {
  let answer = 0;
  people.sort((a, b) => a - b);
  let i = 0;
  let j = people.length - 1;
  while (i < j) {
    if (people[i] + people[j] <= limit) {
      i++;
      j--;
    } else {
      j--;
    }
    answer++;
  }
  if (i === j) answer++;
  return answer;
};

//javascript sort는 문자열 기준 sort가 디폴트 값이기 떄문에 숫자로 sort하고 싶을땐 안에 인자를 쓰도록 하자
console.log(solution(people, limit));
