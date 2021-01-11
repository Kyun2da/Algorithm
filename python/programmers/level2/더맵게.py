import heapq


def solution(scoville, K):
    heap = []
    for x in scoville:
        heapq.heappush(heap, x)

    ans = 0
    while True:
        length = len(heap)
        for i in range(length):
            if heap[i] < K:
                break
            elif heap[i] >= K and i == length - 1:
                return ans
        if length == 1:
            return -1
        x = heapq.heappop(heap)
        y = heapq.heappop(heap)
        newSco = x + y * 2
        heapq.heappush(heap, newSco)
        # print(heap)
        ans += 1


print(solution([1, 2, 3, 9, 10, 12], 7))
