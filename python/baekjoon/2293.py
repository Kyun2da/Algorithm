import sys

n, k = map(int, input().split())

arr = []

for _ in range(n):
    num = int(sys.stdin.readline().rstrip())
    arr.append(num)

dp = [0] * (k+1)
dp[0] = 1
for x in arr:
    for i in range(x, k + 1):
        dp[i] += dp[i - x]

print(dp[k])
