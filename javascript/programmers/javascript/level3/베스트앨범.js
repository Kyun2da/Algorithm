const genres = ["classic", "pop", "classic", "classic", "pop"];
const plays = [500, 600, 150, 800, 2500];

const sum = (a) => {
  return a.reduce((acc, cur) => {
    return acc + cur[0];
  }, 0);
};

const solution = (genres, plays) => {
  const answer = [];
  const genre = [];
  const play = [];
  for (let i = 0; i < genres.length; i++) {
    if (genre.includes(genres[i])) {
      //console.log(genre);
      const idx = genre.indexOf(genres[i]);
      play[idx].push([plays[i], i]);
    } else {
      genre.push(genres[i]);
      play.push([[plays[i], i]]);
    }
  }

  play.sort((a, b) => {
    return sum(b) - sum(a);
  });

  for (let i = 0; i < play.length; i++) {
    play[i].sort((a, b) => {
      return b[0] - a[0];
    });
  }

  for (let i = 0; i < play.length; i++) {
    for (let j = 0; j < play[i].length; j++) {
      if (j === 2) break;
      answer.push(play[i][j][1]);
    }
  }
  return answer;
};

console.log(solution(genres, plays));
