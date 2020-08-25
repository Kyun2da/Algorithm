import sys

def paperCount(x, y, n):
    global arr, blue, white
    check = arr[x][y]
    for i in range(x, x + n):
        for j in range(y, y + n):
            if check != arr[i][j]:
                paperCount(x, y, n // 2)  # 1사분면
                paperCount(x, y + n // 2, n // 2)  # 2사분면
                paperCount(x + n // 2, y, n // 2)  # 3사분면
                paperCount(x + n // 2, y + n // 2, n // 2)  # 4사분면
                return
    if check==0:#모두 흰색일 때
        white+=1
        return
    else: #모두 파란색일 때
        blue+=1
        return


N = int(input())

arr = []
blue = 0
white = 0
for _ in range(N):
    arr.append(list(map(int, sys.stdin.readline().split())))
paperCount(0,0,N)
print(white)
print(blue)