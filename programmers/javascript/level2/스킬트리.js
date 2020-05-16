//스킬트리  
//스킬에 순서를 따라야함
// 단어마다 for문을 돌면서 스킬이 있으면 하고 없으면 안한다?
const skill = "CBD";
const skill_trees = ["BACDE", "CBADF", "AECB", "BDA"];   // BCD  CBD CB BDA

function solution(skill, skill_trees) {
    let answer = 0;
    let arr = skill.split("");
    for(let i=0; i<skill_trees.length; i++){
        let tree = skill_trees[i].split("").filter(value => arr.includes(value)).join("");
        if(tree === skill.substring(0,tree.length)){
            answer++;
        }
    }
    return answer;
}

console.log(solution(skill,skill_trees));