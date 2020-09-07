import sys


def dfs(path, now, total):
    global minNum
    if len(path) == n and arr[now][path[0]] != 0:
        minNum = min(minNum, total + arr[now][path[0]])
    for i in range(n):
        if i in path or arr[now][i] == 0 or total > minNum: continue
        path.append(i)
        dfs(path, i, total + arr[now][i])
        path.pop()


arr = []
n = int(input())
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().rstrip().split())))

minNum = float('inf')
vis = []
for i in range(n):
    vis.append(i)
    dfs(vis, i, 0)
    vis.pop()

print(minNum)
