n = int(input())

arr = list(map(int, input().split()))
dp = [0] * n

for i in range(0, n):
    dp[i] = 1
    for j in range(0, i):
        if arr[i] < arr[j] and dp[i] < dp[j] + 1:
            dp[i] = dp[j] + 1

print(max(dp))
