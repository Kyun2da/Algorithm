from itertools import combinations


def solution(relation):
    rowNum = len(relation)
    colNum = len(relation[0])

    # 모든 가능한 후보들을 뽑는다.
    candidates = []
    for i in range(1, colNum + 1):
        candidates.extend(combinations(range(colNum), i))

    # 유일성 만족 확인
    final = []
    for keys in candidates:
        tmp = [tuple([item[key] for key in keys]) for item in relation]
        if len(set(tmp)) == rowNum:
            final.append(keys)

    # 최소성 만족 확인
    answer = set(final[:])
    for i in range(len(final)):
        for j in range(i + 1, len(final)):
            if len(final[i]) == len(set(final[i]).intersection(set(final[j]))):
                answer.discard(final[j])
    return len(answer)


print(solution([["100", "ryan", "music", "2"], ["200", "apeach", "math", "2"], ["300", "tube", "computer", "3"],
                ["400", "con", "computer", "4"], ["500", "muzi", "music", "3"], ["600", "apeach", "music", "2"]]))
