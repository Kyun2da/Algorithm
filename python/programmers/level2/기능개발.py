import math


def solution(progresses, speeds):
    answer = []
    tmp = []
    for p, s in zip(progresses, speeds):
        tmp.append(math.ceil((100 - p) / s))
    count = 1
    num = tmp[0]
    for i in range(1, len(tmp)):
        if num < tmp[i]:
            answer.append(count)
            count = 1
            num = tmp[i]
        else:
            count += 1
    answer.append(count)
    return answer


print(solution([95, 90, 99, 99, 80, 99], [1, 1, 1, 1, 1, 1]))


# def solution(progresses, speeds):
#     Q = []
#     for p, s in zip(progresses, speeds):
#         if len(Q) == 0 or Q[-1][0] < -((p - 100) // s):
#             Q.append([-((p - 100) // s), 1])
#         else:
#             Q[-1][1] += 1
#     return [q[1] for q in Q]
