def solution(n):
    answer = 0
    dp = [0] * 10001
    for i in range(1, n):
        dp[i] = dp[i - 1] + i

    for i in range(n - 1):
        for j in range(i + 1, n):
            if dp[j] - dp[i] == n:
                answer += 1
            elif dp[j] - dp[i] > n:
                break
    return answer + 1


print(solution(15))
