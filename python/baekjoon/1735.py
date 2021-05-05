a, b = map(int, input().split())
c, d = map(int, input().split())

e = a * d + b * c
f = b * d


def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y, x % y)


mok = gcd(e, f)
print(e // mok, f // mok)
