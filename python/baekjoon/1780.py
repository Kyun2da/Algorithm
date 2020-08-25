import sys


def numberOfPaper(x, y, n):
    global arr, numOfMinusOne, numOfOne, numOfZero
    check = arr[x][y]
    for i in range(x, x + n):
        for j in range(y, y + n):
            if check != arr[i][j]:
                tmp = n // 3
                for k in range(0, 3):
                    for m in range(0, 3):
                        numberOfPaper(x + tmp * k, y + tmp * m, n // 3)
                return
    if check == -1:
        numOfMinusOne += 1
    elif check == 0:
        numOfZero += 1
    else:
        numOfOne += 1


N = int(input())

arr = []
numOfMinusOne = 0
numOfOne = 0
numOfZero = 0

for _ in range(N):
    arr.append(list(map(int, sys.stdin.readline().split())))
numberOfPaper(0, 0, N)
print(numOfMinusOne)
print(numOfZero)
print(numOfOne)
