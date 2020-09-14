import sys
from collections import deque


def bfs():
    q.append([0, 0, 0])
    vis[0][0][0] = 1
    while q:
        x, y, z = q.popleft()
        for i in range(4):
            dx = x + dir[i][0]
            dy = y + dir[i][1]
            if 0 <= dx < n and 0 <= dy < m:
                if arr[dx][dy] == 0 and vis[dx][dy][z] == -1:
                    vis[dx][dy][z] = vis[x][y][z] + 1
                    q.append([dx, dy, z])
                elif z == 0 and arr[dx][dy] == 1 and vis[dx][dy][1] == -1:
                    vis[dx][dy][1] = vis[x][y][z] + 1
                    q.append([dx, dy, 1])


n, m = map(int, input().split())

arr = []
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().rstrip())))

vis = [[[-1] * 2 for _ in range(m)] for _ in range(n)]
q = deque()
dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]

bfs()
ans1, ans2 = vis[n - 1][m - 1][0], vis[n - 1][m - 1][1]

if ans1 == -1 and ans2 != -1:
    print(ans2)
elif ans1 != -1 and ans2 == -1:
    print(ans1)
else:
    print(min(ans1, ans2))
