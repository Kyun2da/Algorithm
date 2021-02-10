def solution(m, n, puddles):
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    dp[1][1] = 1
    for puddle in puddles:
        y, x = puddle
        dp[y][x] = 0

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if i == 1 and j == 1:
                continue
            if [i, j] in puddles:
                continue
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

    print(dp)
    return dp[-1][-1] % 1_000_000_007


print(solution(4, 3, [[2, 2]]))
