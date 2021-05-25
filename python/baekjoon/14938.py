import sys
import heapq

input = sys.stdin.readline

INF = sys.maxsize
ans = 0
n, m, r = map(int, input().split())

node = [0] + list(map(int, input().split()))

graph = [[] for _ in range(n + 1)]

for _ in range(r):
    a, b, l = map(int, input().split())
    graph[a].append((b, l))
    graph[b].append((a, l))


def dijk(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))


for i in range(1, n + 1):
    distance = [INF] * (n + 1)
    dijk(i)
    tmp = 0
    for j in range(1, n + 1):
        if distance[j] <= m:
            tmp += node[j]
    ans = max(ans, tmp)

print(ans)
