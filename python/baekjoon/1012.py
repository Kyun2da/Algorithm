import sys
sys.setrecursionlimit(10**6)

t = int(input())

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


def dfs(x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m and not vis[nx][ny] and arr[nx][ny]:
            vis[nx][ny] = True
            dfs(nx, ny)


for _ in range(t):
    m, n, k = map(int, input().split())

    arr = [[0] * m for _ in range(n)]
    vis = [[False] * m for _ in range(n)]
    ans = 0
    for _ in range(k):
        a, b = map(int, sys.stdin.readline().split())
        arr[b][a] = 1

    for i in range(n):
        for j in range(m):
            if not vis[i][j] and arr[i][j]:
                vis[i][j] = True
                dfs(i, j)
                ans += 1
    print(ans)
