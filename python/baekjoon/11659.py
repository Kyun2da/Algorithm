# dp로 해결하자

import sys

input = sys.stdin.readline

n, m = map(int, input().split())

arr = list(map(int, input().split()))

dp = [0]
for i in range(1, n + 1):
    dp.append(dp[i - 1] + arr[i - 1])

# print(dp)
for _ in range(m):
    a, b = map(int, input().split())
    print(dp[b] - dp[a - 1])
