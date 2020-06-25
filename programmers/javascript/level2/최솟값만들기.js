const A = [1, 2, 3, 5, 4];
const B = [3, 4, 9, 7, 6];

const solution = (A, B) => {
  let sum = 0;
  A.sort();
  B.sort((a, b) => {
    return b - a;
  });

  for (let i = 0; i < A.length; i++) {
    sum += A[i] * B[i];
  }
  return sum;
};

console.log(solution(A, B));
