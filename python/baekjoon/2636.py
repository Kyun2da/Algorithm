import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

before_count = 0
sec = 0


def isMelt():
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 1:
                return False
    return True


def count_cheeze():
    count = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 1:
                count += 1
    return count


while not isMelt():
    sec += 1
    before_count = count_cheeze()
    vis = [[False] * m for _ in range(n)]
    q = deque()
    q.append([0, 0])
    tmp = []
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and not vis[nx][ny]:
                vis[nx][ny] = True
                if arr[nx][ny] == 0:
                    q.append([nx, ny])
                if arr[nx][ny] == 1 and [nx, ny] not in tmp:
                    tmp.append([nx, ny])

    for x, y in tmp:
        arr[x][y] = 0

print(sec)
print(before_count)
