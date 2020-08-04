const cacheSize = 3;

const cities = [
  "Jeju",
  "Pangyo",
  "Seoul",
  "Jeju",
  "Pangyo",
  "Seoul",
  "Jeju",
  "Pangyo",
  "Seoul",
];

const solution = (cacheSize, cities) => {
  let answer = 0;
  cities = cities.map((it) => it.toUpperCase());
  let arr = [];
  if (cacheSize == 0) return cities.length * 5;
  for (let i = 0; i < cities.length; i++) {
    const idx = arr.findIndex((it) => it === cities[i]);
    if (idx !== -1) {
      arr.splice(idx, 1);
      answer += 1;
    } else if (arr.length === cacheSize) {
      answer += 5;
      arr.shift();
    } else {
      answer += 5;
    }
    arr.push(cities[i]);
    //console.log(arr);
  }
  return answer;
};

console.log(solution(cacheSize, cities));
