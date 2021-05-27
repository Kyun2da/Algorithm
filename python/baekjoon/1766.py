import sys
from heapq import heappush, heappop

input = sys.stdin.readline

n, m = map(int, input().split())
ans = []
graph = [[] for _ in range(n + 1)]
indegree = [0 for _ in range(n + 1)]
heap = []

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

for i in range(1, n + 1):
    if indegree[i] == 0:
        heappush(heap, i)

while heap:
    tmp = heappop(heap)
    ans.append(tmp)
    for j in graph[tmp]:
        indegree[j] -= 1
        if indegree[j] == 0:
            heappush(heap, j)

print(' '.join(map(str, ans)))
