import sys
import heapq


def prim(x):
    q = []
    vis = [False] * (v + 1)
    vis[x] = True
    ans = 0
    edgeCount = 0

    # 우선순위 큐에 해당 정점에 이어져있는 간선 정보 삽입
    for item in adj[x]:
        heapq.heappush(q, item)

    # 우선순위 큐가 빌 때까지 계속 간선을 추가해준다.
    while q:
        w, v1 = heapq.heappop(q)
        if not vis[v1]:
            vis[v1] = True
            edgeCount += 1
            ans += w
            for item in adj[v1]:
                heapq.heappush(q, item)
        if edgeCount == v - 1:
            return ans
    return 0


v, e = map(int, sys.stdin.readline().split())
adj = [[] for _ in range(v + 1)]

for _ in range(e):
    a, b, weight = map(int, sys.stdin.readline().split())
    adj[a].append([weight, b])
    adj[b].append([weight, a])

print(prim(1))
