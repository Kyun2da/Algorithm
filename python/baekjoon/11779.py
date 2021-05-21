import sys
from heapq import heappop, heappush


def dijk(start, end):
    dist = [INF for _ in range(n + 1)]
    dist[start] = 0
    path = [-1] * (n + 1)
    q = []
    heappush(q, [0, start])
    while q:
        cost, now = heappop(q)
        for p, c in graph[now]:
            c += cost
            if c < dist[p]:
                dist[p] = c
                path[p] = now
                heappush(q, (c, p))

    return dist[end], path


input = sys.stdin.readline
INF = sys.maxsize

n = int(input())
m = int(input())

graph = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b, wei = map(int, input().split())
    graph[a].append((b, wei))

start, end = map(int, input().split())

cost, path = dijk(start, end)

pathResult = [end]
tmp = end
while path[tmp] != -1:
    pathResult.append(path[tmp])
    tmp = path[tmp]

print(cost)
print(len(pathResult))
print(' '.join(map(str, pathResult[::-1])))
