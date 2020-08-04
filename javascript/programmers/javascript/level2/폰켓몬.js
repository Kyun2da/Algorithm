const nums = [3, 1, 2, 3];

const solution = (nums) => {
  let chooseNum = Math.floor(nums.length / 2);
  const arr = Array.from(new Set(nums));

  if (arr.length >= chooseNum) {
    return chooseNum;
  } else {
    return arr.length;
  }
};

console.log(solution(nums));
