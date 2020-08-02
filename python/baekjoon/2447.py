def recursive(t,x,y):
    if t==1: return

    sx, ex = x + t//3, x+(t//3)*2
    sy, ey = y + t//3, y+(t//3)*2
    for i in range(sx,ex):
        for j in range(sy,ey):
                table[i][j]= ' '

    recursive(t//3,x,y)
    recursive(t // 3, sx, y)
    recursive(t // 3, ex, y)
    recursive(t // 3, x, sy)
    recursive(t // 3, ex, sy)
    recursive(t // 3, x, ey)
    recursive(t // 3, sx, ey)
    recursive(t // 3, ex, ey)



num = int(input())
table = [['*'] * num for _ in range(num)]
recursive(num,0,0)
for t in table: print(''.join(t))