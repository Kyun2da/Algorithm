# dp와 dfs 를 사용하여 경로를 찾는 문제

import sys

sys.setrecursionlimit(10**9)

m, n = map(int, sys.stdin.readline().split())
arr = []
for _ in range(m):
    arr.append(list(map(int, sys.stdin.readline().split())))
dp = [[-1] * n for _ in range(m)]

dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]


def dfs(x, y):
    if x == m - 1 and y == n - 1:
        return 1
    if dp[x][y] == -1:
        dp[x][y] = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < m and 0 <= ny < n and arr[nx][ny] < arr[x][y]:
                dp[x][y] += dfs(nx, ny)

    return dp[x][y]


print(dfs(0, 0))
