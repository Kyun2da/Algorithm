def mul(a, b):
    if b == 0:
        return 1
    elif b == 1:
        return a
    elif b % 2 > 0:
        return mul(a, b - 1) * a
    else:
        d = mul(a, b // 2)
        d %= c
        return d ** 2 % c


a, b, c = map(int, input().split())

print(mul(a, b) % c)