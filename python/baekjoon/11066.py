import sys

n = int(input())

for _ in range(n):
    k = int(sys.stdin.readline().rstrip())
    arr = list(map(int, sys.stdin.readline().rstrip().split()))

    sum = [arr[0]]
    for i in range(1, k):
        sum.append(arr[i] + sum[i - 1])  # 첫번째부터 n번째까지의 파일의 합

    dp = [[0] * k for _ in range(k)]
    for i in range(1, k):  # 구하려는 구간의 길이
        for j in range(0, k - i): # 구간의 시작 j
            dp[j][i + j] = float('inf')
            for m in range(j, i + j):
                if j == 0:
                    dp[j][j + i] = min(dp[j][j + i], dp[j][m] + dp[m + 1][j + i] + sum[j + i])
                else:
                    dp[j][j + i] = min(dp[j][j + i], dp[j][m] + dp[m + 1][j + i] + sum[j + i] - sum[j - 1])
    print(dp[0][-1])
