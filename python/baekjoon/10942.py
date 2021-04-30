import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
dp = [[0] * n for _ in range(n)]

for i in range(n):
    dp[i][i] = 1

for i in range(n - 1):
    if arr[i] == arr[i + 1]:
        dp[i][i + 1] = 1

for i in range(2, n):
    for j in range(n - i):
        if arr[j] == arr[j + i] and dp[j + 1][j + i - 1] == 1:
            dp[j][i + j] = 1

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    print(dp[a - 1][b - 1])
