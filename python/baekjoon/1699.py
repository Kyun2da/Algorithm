n = int(input())

dp = [0] * (n + 1)

powNum = 1
dp[0], dp[1] = 0, 1

for i in range(1, n + 1):
    dp[i] = i
    for j in range(1, i):
        if j * j > i:
            break
        dp[i] = min(dp[i], dp[i - j * j] + 1)

print(dp[n])
