import sys
import heapq

n = int(sys.stdin.readline())

heap = []

for _ in range(n):
    k = int(sys.stdin.readline())
    if k ==0:
        if heap:
            print(-heap[0])
            heapq.heappop(heap)
        else:
            print(0)
    else:
        heapq.heappush(heap,-k)

