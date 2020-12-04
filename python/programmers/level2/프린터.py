from collections import deque


def solution(priorities, location):
    answer = 1
    indexArr = deque([i for i in range(len(priorities))])
    q = deque(priorities)
    while True:
        maxnum = max(q)
        # print(maxnum)
        while maxnum != q[0]:
            tmp = q.popleft()
            q.append(tmp)
            tmp = indexArr.popleft()
            indexArr.append(tmp)
        if indexArr[0] != location:
            answer += 1
            q.popleft()
            indexArr.popleft()
            # print(q)
        else:
            break

    return answer


print(solution([2, 1, 3, 2], 2))


# def solution(priorities, location):
#     queue =  [(i,p) for i,p in enumerate(priorities)]
#     answer = 0
#     while True:
#         cur = queue.pop(0)
#         if any(cur[1] < q[1] for q in queue):
#             queue.append(cur)
#         else:
#             answer += 1
#             if cur[0] == location:
#                 return answer