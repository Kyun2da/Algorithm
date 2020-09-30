import copy


def solution(n, lost, reserve):
    answer = n - len(lost)
    # 먼저 여벌있는 학생이 도난당했을때 자기꺼 입을 수있도록해줌
    newlost = copy.deepcopy(lost)
    for lostp in lost:
        if lostp in reserve:
            reserve.remove(lostp)
            newlost.remove(lostp)
            answer += 1

    for lostp in newlost:
        if lostp - 1 in reserve:
            reserve.remove(lostp - 1)
            answer += 1
        if lostp + 1 in reserve:
            reserve.remove(lostp + 1)
            answer += 1

    return answer


print(solution(5, [2, 4], [1, 3, 5]))
