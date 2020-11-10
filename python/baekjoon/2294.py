n, k = map(int, input().split())

INF = 1e9

coin = sorted(list(set(int(input()) for _ in range(n))))
dp = [INF] * 10001
dp[0] = 0

for i in range(1, k + 1):
    for c in coin:
        if i - c < 0:
            break
        dp[i] = min(dp[i], dp[i - c] + 1)
print(dp[k] if dp[k] != INF else -1)
