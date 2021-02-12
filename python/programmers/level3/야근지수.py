from heapq import heappush, heappop, heapify


def solution(n, works):
    if sum(works) < n: return 0
    works = [-i for i in works]
    heapify(works)
    while n > 0:
        heappush(works, heappop(works) + 1)
        n -= 1
    return sum([i ** 2 for i in works])


print(solution(4, [4, 3, 3]))
