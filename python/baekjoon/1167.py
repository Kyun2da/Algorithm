import sys

input = sys.stdin.readline

n = int(input())
graph = [[] for _ in range(n + 1)]


def dfs(x, wei):
    for node in graph[x]:
        i, j = node
        if vis[i] == -1:
            vis[i] = wei + j
            dfs(i, wei + j)


for _ in range(n):
    tmp = list(map(int, input().split()))
    node = tmp[0]
    for i in range((len(tmp) - 2) // 2):
        graph[node].append([tmp[i * 2 + 1], tmp[i * 2 + 2]])

vis = [-1] * (n + 1)
vis[1] = 0
dfs(1, 0)
end_node = vis.index(max(vis))

vis = [-1] * (n + 1)
vis[end_node] = 0
dfs(end_node, 0)
print(max(vis))
