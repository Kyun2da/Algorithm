def solution(n):
    mod = 1234567

    pibo = [0] * (n + 1)
    pibo[1] = 1
    for i in range(2, n + 1):
        pibo[i] = (pibo[i - 1] + pibo[i - 2]) % mod
    return pibo[n] % mod


print(solution(3))
