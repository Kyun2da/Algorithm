import sys
from collections import deque

sys.setrecursionlimit(10 ** 3)

input = sys.stdin.readline

# 인풋 받기
n, m = map(int, input().split())

arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

ans = 0

# 방향 배열
dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]


# bfs로 빙산을 방문해 한번에 모든 빙산을 방문할 수있는지 vis 배열로 처리
def bfs(a, b):
    q = deque()
    q.append([a, b])
    vis[a][b] = True
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and not vis[nx][ny] and arr[nx][ny] != -1:
                vis[nx][ny] = True
                q.append([nx, ny])


# 계산 편의를 위해 0을 -1로 바꿈
for i in range(n):
    for j in range(m):
        if arr[i][j] == 0:
            arr[i][j] = -1

ans = 0
vis = []

while True:
    # 빙산이 끝까지 다녹았는데도 분리되지 않았을때 0으로 출력하고 끝냄
    count = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] == -1:
                count += 1
    if count == n * m:
        print(0)
        break
    vis = [[False] * m for _ in range(n)]
    iceMountain = []
    for i in range(n):
        for j in range(m):
            if arr[i][j] != -1:
                iceMountain.append([i, j])
    bfs(iceMountain[0][0], iceMountain[0][1])
    for item in iceMountain:
        x, y = item
        # 빙산이 사라지지도 않고 방문하지도 않은 빙산이 있다면 빙산이 분리되어 있다는 뜻
        if arr[x][y] != -1 and not vis[x][y]:
            print(ans)
            sys.exit()

    # 빙산이 분리되어 있지 않다면 빙산을 1년 후를 그린다.
    change = []
    for item in iceMountain:
        x, y = item
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and arr[nx][ny] == -1:
                arr[x][y] = max(arr[x][y] - 1, 0)
        if arr[x][y] == 0:
            change.append([x, y])

    for idx in change:
        x, y = idx
        arr[x][y] = -1

    # for i in range(n):
    #     for j in range(m):
    #         print(arr[i][j], end=" ")
    #     print()

    ans += 1
