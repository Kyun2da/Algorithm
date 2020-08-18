def gcd(N, M):
    while M > 0:
        tmp = M
        M = N % M
        N = tmp
    return N


def lcm(N, M):
    return N * M // gcd(N, M)


N, M = map(int, input().split())

print(gcd(N, M))
print(lcm(N, M))
