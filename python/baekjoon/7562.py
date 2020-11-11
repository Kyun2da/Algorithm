import sys
from collections import deque

input = sys.stdin.readline

t = int(input())

dx = [-1, -2, -2, -1, 1, 2, 2, 1]
dy = [-2, -1, 1, 2, 2, 1, -1, -2]

for _ in range(t):
    n = int(input())
    a, b = map(int, input().split())
    dest = list(map(int, input().split()))
    arr = [[0] * n for _ in range(n)]
    vis = [[0] * n for _ in range(n)]
    flag = False
    q = deque()
    q.append([a, b, 0])
    while q:
        x, y, num = q.popleft()
        if x == dest[0] and y == dest[1]:
            print(num)
            break
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n and vis[nx][ny] == 0:
                vis[nx][ny] = num + 1
                q.append([nx, ny, num + 1])
