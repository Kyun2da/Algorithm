n = int(input())

arr = list(map(int, input().split()))

dp = [[0] * n for _ in range(2)]

dp[0][0], dp[1][0] = arr[0], arr[0]
for i in range(1, n):
    dp[0][i] = max(dp[1][i - 1], dp[0][i - 1] + arr[i])
    dp[1][i] = max(dp[1][i - 1] + arr[i], arr[i])

maxNum = float('-inf')
for i in range(2):
    for j in range(n):
        if maxNum < dp[i][j]:
            maxNum = dp[i][j]

print(maxNum)
