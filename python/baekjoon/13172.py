from math import gcd

mod = 1000000007
ans = 0


def mul(x, y):
    if y == 1: return x
    if y % 2: return x * mul(x, y - 1) % mod
    t = mul(x, y // 2)
    return t * t % mod


m = int(input())

for _ in range(m):
    n, s = map(int, input().split())
    g = gcd(n, s)
    n //= g
    s //= g

    ans += s * mul(n, mod - 2) % mod
    ans %= mod

print(ans)
