n, m = map(int, input().split())


def factorial(x):
    if x == 1:
        return 1
    return x * factorial(x - 1)


print(factorial(n) // (factorial(n - m) * factorial(m)))
