# 징검다리의 stones
# 최대 띄어서 건널수 있는 다리 수
# 최대 몇명까지 건널 수 있는가
# 2 4 5 3 2 1 4 2 5 1
# 1 3 4 2 1 0 3 1 4 0
# 0 2 3 1 0 0 2 0 3 0
# 0 1 2 0 0 0 1 0 2 0


# def solution(stones, k):
#     answer = 0
#     while True:  # 징검다리를 못 건너는 사람이 있을때 까지 시행
#         flag = 0
#         for i, stone in enumerate(stones):
#             if stone == 0:
#                 flag += 1
#             else:
#                 stones[i] -= 1
#                 flag = 0
#             if flag == k:
#                 return answer
#         answer += 1

import copy


def solution(stones, k):
    left = 1
    right = 1e9

    length = len(stones)
    while left <= right:
        mid = (left + right) // 2
        tmp = copy.deepcopy(stones)
        for i in range(length):
            tmp[i] -= mid

        cnt = 0
        flag = False
        for i in range(length):
            if tmp[i] <= 0:
                cnt += 1
            else:
                cnt = 0

            if cnt >= k:
                flag = True
                break

        if flag:
            right = mid - 1
        else:
            left = mid + 1

    return left


print(solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3))
