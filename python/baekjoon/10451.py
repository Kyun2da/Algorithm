import sys
from collections import deque

input = sys.stdin.readline

t = int(input())


def bfs(num):
    q = deque()
    q.append(num)
    while q:
        length = len(q)
        for _ in range(length):
            x = q.popleft()
            for i in graph[x]:
                if not vis[i]:
                    vis[i] = True
                    q.append(i)

for _ in range(t):
    ans = 0
    n = int(input())
    arr = list(map(int, input().split()))
    vis = [False] * (n + 1)
    graph = [[] for _ in range(n + 1)]
    for i, v in enumerate(arr):
        graph[i+1].append(v)
        graph[v].append(i+1)

    for i in range(1, n + 1):
        if not vis[i]:
            ans += 1
            bfs(i)
    print(ans)


