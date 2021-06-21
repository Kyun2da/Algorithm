import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
m = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
plan = list(map(int, input().split()))
graph = [[] for _ in range(n)]

for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            graph[i].append(j)

for i in range(len(plan)):
    vis = [False] * n
    q = deque()
    if i != len(plan) - 1:
        start, end = plan[i] - 1, plan[i + 1] - 1
    else:
        start, end = plan[i] - 1, plan[-1] - 1

    q.append(start)
    vis[start] = True
    while q:
        x = q.popleft()
        for y in graph[x]:
            if not vis[y]:
                vis[y] = True
                q.append(y)

    if not vis[end]:
        print("NO")
        exit()

print("YES")
