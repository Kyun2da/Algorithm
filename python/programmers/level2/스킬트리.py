def solution(skill, skill_trees):
    answer = 0
    # 스킬트리를 순회하면서 검사
    for s in skill_trees:
        minIdx = 0  # 먼저배워야할 스킬
        flag = True  # 최종적으로 가능한 스킬트리인지 여부를 확인하는 플래그
        for alpha in s:
            idx = skill.find(alpha)
            # print(idx)
            if idx == -1:  # 스킬트리에 없는건 그냥 스킵
                continue
            elif idx > minIdx:  # 선행스킬을 안배웠다면 불가능한 스킬트리
                flag = False
                break
            else:  # 선행스킬이므로 그다음스킬배울수있음
                minIdx += 1
        if flag:
            # print(s)
            answer += 1

    return answer


print(solution("CBD", ["BACDE", "CBADF", "AECB", "BDA"]))
