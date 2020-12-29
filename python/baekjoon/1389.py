import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())

graph = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

# print(graph)

ans = 1e9
ansIdx = 1e9
q = deque()


# bfs로 케빈 베이컨 수 구하기
def bfs(k):
    vis = [False] * (n + 1)  # 방문 여부 배열
    tmp = 1  # 정점을 몇번 거쳐 해당 노드를 방문했는지의 거리
    bfsAns = [0] * (n + 1)  # 정답이 들어갈 배열
    vis[k] = True
    q.append(k)
    while q:
        length = len(q)
        for _ in range(length):
            x = q.popleft()
            for i in graph[x]:
                if not vis[i]:
                    q.append(i)
                    vis[i] = True
                    bfsAns[i] = tmp
        tmp += 1
    # print(bfsAns)
    return sum(bfsAns)


# 가장 작은 케빈 베이컨 수를 구한다.
for i in range(1, n + 1):
    q.clear()
    num = bfs(i)
    if ans > num:
        ans = num
        ansIdx = i

print(ansIdx)
