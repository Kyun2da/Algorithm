import sys
input = sys.stdin.readline

direction = [[0, -1], [-1, 0], [0, 1], [1, 0]]
n, m = map(int, input().split())
x, y, d = map(int, input().split())
s = []
for i in range(n):
    s.append(list(map(int, input().split())))

exitTrue = True
# 1번
while exitTrue:
    s[x][y] = 2
    # 2번
    while True:
        isTrue = True
        for i in range(4):
            nx = x + direction[d][0]
            ny = y + direction[d][1]
            d = d - 1 if d != 0 else 3
            if s[nx][ny] == 0:
                x, y = nx, ny
                isTrue = False
                break
        if isTrue:
            if d == 0: rx, ry = x + 1, y
            elif d == 1: rx, ry = x, y - 1
            elif d == 2: rx, ry = x - 1, y
            elif d == 3: rx, ry = x, y + 1
            if s[rx][ry] == 1:
                exitTrue = False
                break
            else:
                x, y = rx, ry
        else:
            break
cnt = 0
for i in s:
    cnt += i.count(2)
print(cnt)