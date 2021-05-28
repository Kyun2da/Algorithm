import sys

input = sys.stdin.readline
INF = sys.maxsize

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
dp = [[None] * (1 << n) for _ in range(n)]


def tsp(last, vis):
    if vis == (1 << n) - 1:
        return arr[last][0] or INF

    if dp[last][vis] is not None:
        return dp[last][vis]

    tmp = INF
    for i in range(n):
        if vis & (1 << i) == 0 and arr[last][i] != 0:
            tmp = min(tmp, tsp(i, vis | (1 << i)) + arr[last][i])
    dp[last][vis] = tmp
    return tmp


print(tsp(0, 1 << 0))
