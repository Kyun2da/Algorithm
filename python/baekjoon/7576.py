import sys
from collections import deque

sys.setrecursionlimit(10 ** 6)

m, n = map(int, sys.stdin.readline().split())

dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]
arr = []
day = -1
flag = True
q = deque()
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

for i in range(n):
    for j in range(m):
        if arr[i][j] == 1:
            q.append([i, j])

while q:
    day += 1
    for _ in range(len(q)):
        x, y = q.popleft()
        for i in range(4):
            dx = x + dir[i][0]
            dy = y + dir[i][1]
            if 0 <= dx < n and 0 <= dy < m and arr[dx][dy] == 0:
                # print([dx, dy])
                q.append([dx, dy])
                arr[dx][dy] = 1

for i in range(n):
    for j in range(m):
        if arr[i][j] == 0:
            flag = False
            print(-1)
            sys.exit()

print(day)
