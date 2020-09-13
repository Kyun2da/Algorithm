import sys
sys.setrecursionlimit(10**6)

def dfs(x, y):
    arr[x][y] = 2

    for i in range(8):
        dx = x+dir[i][0]
        dy = y+dir[i][1]
        if isIsland(dx,dy):
            dfs(dx,dy)

# 방향 : 대각선 위 부터 시계방향
dir = [[-1, -1], [-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1]]

def isIsland(x,y):
    if 0<=x<h and 0<=y<w and arr[x][y]==1:
        return True
    return False

while True:
    w, h = map(int, sys.stdin.readline().split())
    if w == 0 and h == 0:
        break

    arr = []
    for _ in range(h):
        arr.append(list(map(int, sys.stdin.readline().split())))

    count = 0
    for i in range(h):
        for j in range(w):
            if arr[i][j] == 1:
                dfs(i, j)
                count += 1

    print(count)
