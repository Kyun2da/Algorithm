import sys
from collections import deque
import copy


def bfs():
    global ans
    cArr = copy.deepcopy(arr)
    for i in range(n):
        for j in range(m):
            if cArr[i][j] == 2:
                q.append([i, j])

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and cArr[nx][ny] == 0:
                cArr[nx][ny] = 2
                q.append([nx, ny])

    cnt = 0
    for row in cArr:
        cnt += row.count(0)
    ans = max(ans, cnt)


def wall(num):
    if num == 3:
        bfs()
        return
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 0:
                arr[i][j] = 1
                wall(num + 1)
                arr[i][j] = 0


n, m = map(int, input().split())

arr = []
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
q = deque()
ans = 0
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

wall(0)
print(ans)
