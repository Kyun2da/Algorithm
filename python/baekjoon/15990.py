import sys

mod = 1000000009
arr = [[0] * 4 for _ in range(100001)]

arr[1][1], arr[1][2], arr[1][3] = 1, 0, 0
arr[2][1], arr[2][2], arr[2][3] = 0, 1, 0
arr[3][1], arr[3][2], arr[3][3] = 1, 1, 1

for i in range(4, 100001):
    arr[i][1] = (arr[i - 1][2] + arr[i - 1][3]) % mod
    arr[i][2] = (arr[i - 2][1] + arr[i - 2][3]) % mod
    arr[i][3] = (arr[i - 3][1] + arr[i - 3][2]) % mod

t = int(input())

for _ in range(t):
    n = int(sys.stdin.readline())
    print(sum(arr[n]) % mod)
