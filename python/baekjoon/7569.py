from collections import deque

dx = [1, -1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]


def bfs():
    while q:
        x, y, z = q.popleft()
        vis[x][y][z] = 1
        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]
            if 0 <= nx < h and 0 <= ny < n and 0 <= nz < m and arr[nx][ny][nz] == 0 and vis[nx][ny][nz] == 0:
                q.append([nx, ny, nz])
                arr[nx][ny][nz] = arr[x][y][z] + 1
                vis[nx][ny][nz] = 1


m, n, h = map(int, input().split())

arr = [[] for _ in range(h)]
vis = [[[0 for _ in range(m)] for _ in range(n)] for _ in range(h)]
for i in range(h):
    for j in range(n):
        arr[i].append(list(map(int, input().split())))

q = deque()
for i in range(h):
    for j in range(n):
        for k in range(m):
            if arr[i][j][k] == 1:
                q.append([i, j, k])

bfs()
for i in range(h):
    for j in range(n):
        for k in range(m):
            if arr[i][j][k] == 0:
                print(-1)
                exit()

maxnum = 0
for i in range(h):
    for j in range(n):
        for k in range(m):
            maxnum = max(maxnum, arr[i][j][k])

print(maxnum - 1)
