import sys
from collections import deque

input = sys.stdin.readline

h, w = map(int, input().split())
arr = [list(map(str, input())) for _ in range(h)]

answer = 0
dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

for i in range(h):
    for j in range(w):
        if arr[i][j] == 'W':
            continue
        vis = [[False] * w for _ in range(h)]
        q = deque()
        q.append([i, j, 0])
        vis[i][j] = True
        while q:
            x, y, value = q.popleft()
            answer = max(answer, value)
            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]
                if 0 <= nx < h and 0 <= ny < w and arr[nx][ny] == 'L' and not vis[nx][ny]:
                    q.append([nx, ny, value + 1])
                    vis[nx][ny] = True

print(answer)
