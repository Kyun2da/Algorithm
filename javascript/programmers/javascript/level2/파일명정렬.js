const files = [
  "img123456712341234123412341233412341234123412341234asdgsadgasdgasdg.png",
  "img103abd4567.png",
  "img023abdc4567.png",
  "img134abdc567.png",
  "IMG013abcd4567.GIF",
  "img234abdc567.JPG",
];

const solution = (files) => {
  let answer = [];
  const arr = [];
  for (let i = 0; i < files.length; i++) {
    const reg = /(\d+)/g;
    const value = files[i].split(reg);
    const file = files[i];
    const head = value[0].toUpperCase();
    let number = value[1];
    if (number.length > 5) {
      number = number.substring(0, 5);
    }
    number = Number(number);
    arr.push({ file: file, head: head, number: number, idx: i });
  }
  //정렬
  arr.sort((a, b) => {
    if (a.head < b.head) return -1;
    else if (a.head > b.head) return 1;
    else {
      if (a.number > b.number) return 1;
      else if (a.number < b.number) return -1;
      else {
        //HEAD, NUMBER가 같은 경우 index로 순서보장
        if (a.idx < b.idx) return -1;
        else return 1;
      }
    }
  });
  //답 구하기
  for (let i = 0; i < arr.length; i++) {
    answer.push(arr[i].file);
  }
  return answer;
};

console.log(solution(files));
