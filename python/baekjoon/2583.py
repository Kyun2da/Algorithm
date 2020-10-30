from collections import deque

m, n, k = map(int, input().split())

arr = [[0] * n for _ in range(m)]
q = deque()
ans = 0
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
width = []
for _ in range(k):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(y1, y2):
        for j in range(x1, x2):
            arr[i][j] = 1


def bfs(a, b):
    q.append([a, b])
    widthnum = 0
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < m and 0 <= ny < n and arr[nx][ny] == 0:
                arr[nx][ny] = 1
                widthnum += 1
                q.append([nx, ny])
    width.append(widthnum if widthnum != 0 else 1)


for i in range(m):
    for j in range(n):
        if arr[i][j] == 0:
            bfs(i, j)
            ans += 1

width.sort()
print(ans)
print(' '.join(map(str, width)))
