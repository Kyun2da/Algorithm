N, K = map(int, input().split())

arr = [[1] * 1001 for _ in range(1001)]

for i in range(2, 1001):
    for j in range(1, i):
        arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % 10007

print(arr[N][K] % 10007)

'''
N, K = map(int, input().split())
dp = [1] * (K + 1)
for i in range(1, K + 1):
    dp[i] = (dp[i - 1] * (N - i + 1) // i)
print(dp[K] % 10007)
'''