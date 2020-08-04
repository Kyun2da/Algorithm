// const participant = ["leo", "kiki", "eden"];
// const completion = ["eden", "kiki"];

// const participant = ["marina", "josipa", "nikola", "vinko", "filipa"];
// const completion = ["josipa", "filipa", "marina", "nikola"];

const participant = ["mislav", "stanko", "mislav", "ana"];
const completion = ["stanko", "ana", "mislav"];

function solution(participant, completion) {
  participant.sort();
  completion.sort();
  for (let i = 0; i < completion.length; i++) {
    if (participant[i] !== completion[i]) {
      return participant[i];
    }
  }
  return participant[participant.length - 1];
}

console.log(solution(participant, completion));
