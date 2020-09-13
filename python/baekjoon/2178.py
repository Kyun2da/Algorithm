# 최단거리 문제는 bfs를 사용하자

import sys
from collections import deque

sys.setrecursionlimit(10 ** 6)

dir = [[-1, 0], [1, 0], [0, -1], [0, 1]]

n, m = map(int, sys.stdin.readline().split())
vis = [[0] * m for i in range(n)]
q = deque()
arr = []
ans = float('inf')
for _ in range(n):
    arr.append(list(map(int, str(sys.stdin.readline().rstrip()))))

q.append([0, 0])
vis[0][0] = 1

while q:
    x, y = q.popleft()
    for i in range(4):
        dx = x + dir[i][0]
        dy = y + dir[i][1]
        if 0 <= dx < n and 0 <= dy < m and arr[dx][dy] == 1 and vis[dx][dy] == 0:
            q.append([dx, dy])
            arr[dx][dy] = arr[x][y] + 1
            vis[dx][dy] = 1

print(arr[n-1][m-1])
