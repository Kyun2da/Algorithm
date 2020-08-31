import sys
import heapq

n = int(sys.stdin.readline())

arr = []
for _ in range(n):
    k = int(sys.stdin.readline())
    if k == 0:
        if arr:
            print(heapq.heappop(arr)[1])
        else:
            print(0)
    else:
        heapq.heappush(arr, (abs(k), k))
