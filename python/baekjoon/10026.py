from collections import deque

n = int(input())
arr = []
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
blindVis = [[0] * n for _ in range(n)]
vis = [[0] * n for _ in range(n)]
blindAns = 0
ans = 0
q = deque()


def bfs(t, color):
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if t == 0:
                if 0 <= nx < n and 0 <= ny < n and vis[nx][ny] == 0 and color == arr[nx][ny]:
                    q.append([nx, ny])
                    vis[nx][ny] = 1
            else:
                if 0 <= nx < n and 0 <= ny < n and blindVis[nx][ny] == 0:
                    if (color == 'B' and arr[nx][ny] == 'B') or (
                            (color == 'R' or color == 'G') and (arr[nx][ny] == 'R' or arr[nx][ny] == 'G')):
                        q.append([nx, ny])
                        blindVis[nx][ny] = 1


for _ in range(n):
    arr.append(list(input()))

for i in range(n):
    for j in range(n):
        if blindVis[i][j] == 0:
            blindAns += 1
            blindVis[i][j] = 1
            q.append([i, j])
            bfs(1, arr[i][j])

for i in range(n):
    for j in range(n):
        if vis[i][j] == 0:
            ans += 1
            vis[i][j] = 1
            q.append([i, j])
            bfs(0, arr[i][j])

print("%d %d" % (ans, blindAns))
