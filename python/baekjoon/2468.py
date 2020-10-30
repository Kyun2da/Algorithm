import sys
from collections import deque


def bfs(a, b):
    dq.append([a, b])
    while dq:
        x, y = dq.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n and vis[nx][ny] == 0:
                vis[nx][ny] = 1
                dq.append([nx, ny])


n = int(input())

arr = []
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
dq = deque()
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

ans = 0
for i in range(100):
    # 잠기면 1 안잠기면 0
    vis = [[0] * n for _ in range(n)]
    tmp = 0
    for j in range(n):
        for k in range(n):
            if arr[j][k] < i:
                vis[j][k] = 1

    for j in range(n):
        for k in range(n):
            if vis[j][k] == 0:
                bfs(j, k)
                tmp += 1

    ans = max(ans, tmp)

print(ans)
