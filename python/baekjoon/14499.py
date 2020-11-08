

arr = []
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]
dice = [0, 0, 0, 0, 0, 0]

n, m, x, y, k = map(int, input().split())
for _ in range(n):
    arr.append(list(map(int, input().split())))
coms = list(map(int,input().split()))

for com in coms:
    # 갈수있는 공간인 경우
    if 0 <= x + dx[com - 1] < n and 0 <= y + dy[com - 1] < m:
        x += dx[com - 1]
        y += dy[com - 1]
        if com == 1:
            dice[0], dice[2], dice[3], dice[5] = dice[3], dice[0], dice[5], dice[2]
        elif com == 2:
            dice[0], dice[2], dice[3], dice[5] = dice[2], dice[5], dice[0], dice[3]
        elif com == 3:
            dice[0], dice[1], dice[4], dice[5] = dice[4], dice[0], dice[5], dice[1]
        else:
            dice[0], dice[1], dice[4], dice[5] = dice[1], dice[5], dice[0], dice[4]

        if arr[x][y] == 0:
            arr[x][y] = dice[5]
        else:
            dice[5] = arr[x][y]
            arr[x][y] = 0
        print(dice[0])
