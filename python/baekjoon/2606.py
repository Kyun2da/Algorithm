import sys


def dfs(num):
    for i in graph[num]:
        if not vis[i]:
            vis[i] = True
            dfs(i)


n = int(input())
m = int(input())

graph = [[] for _ in range(n + 1)]
vis = [False] * (n + 1)
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

vis[1] = True
dfs(1)

print(vis.count(True) - 1)
