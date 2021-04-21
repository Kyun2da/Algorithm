import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize

n, e = map(int, input().split())

graph = [[] for _ in range(n + 1)]
for _ in range(e):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
    graph[b].append([a, c])

v1, v2 = map(int, input().split())


def dijkstra(start):
    q = []
    distance = [INF] * (n + 1)
    distance[start] = 0

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

    return distance


one = dijkstra(1)
v1_distance = dijkstra(v1)
v2_distance = dijkstra(v2)

answer = min(one[v1] + v1_distance[v2] + v2_distance[n], one[v2] + v2_distance[v1] + v1_distance[n])

if answer < INF:
    print(answer)
else:
    print(-1)
