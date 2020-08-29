import sys


def divideConquer(x, y, n):
    global arr
    check = arr[x][y]

    for i in range(x, x + n):
        for j in range(y, y + n):
            if check != arr[i][j]:
                print('(', end="")
                divideConquer(x, y, n // 2)  # 1사분면
                divideConquer(x, y + n // 2, n // 2)  # 2사분면
                divideConquer(x + n // 2, y, n // 2)  # 3사분면
                divideConquer(x + n // 2, y + n // 2, n // 2)  # 4사분면
                print(')', end="")
                return
    print(check, end="")


N = int(input())

arr = []
for _ in range(N):
    arr.append(list(map(int, sys.stdin.readline().strip())))

divideConquer(0, 0, N)
