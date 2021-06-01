import sys

input = sys.stdin.readline

ans = sys.maxsize
n, m = map(int, input().split())
size_arr = [0] + list(map(int, input().split()))
value_arr = [0] + list(map(int, input().split()))

dp = [[0] * (sum(value_arr) + 1) for _ in range(n+1)]

for i in range(1, n + 1):
    size = size_arr[i]
    value = value_arr[i]
    for j in range(1, sum(value_arr) + 1):
        if j < value:
            dp[i][j] = dp[i - 1][j]
        else:
            dp[i][j] = max(size + dp[i - 1][j - value], dp[i - 1][j])

        if dp[i][j] >= m:
            ans = min(ans, j)

for i in range(1, n+1):
    for j in range(1, sum(value_arr) + 1):
        print(dp[i][j], end=" ")
    print()

print(ans if m != 0 else 0)
