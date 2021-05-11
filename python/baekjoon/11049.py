import sys

n = int(input())

arr = [list(map(int, input().split())) for _ in range(n)]
dp = [[0] * n for _ in range(n)]

for i in range(1, n):
    for j in range(n - i):
        if i == 1:
            dp[j][j + 1] = arr[j][0] * arr[j][1] * arr[i + j][1]
            continue

        dp[j][j + i] = sys.maxsize
        for k in range(j, j + i):
            dp[j][j + i] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + arr[j][0] * arr[k][1] * arr[i + j][1])

print(dp[0][n-1])
