import sys

sys.setrecursionlimit(10 ** 6)


def factorial(n):
    if n == 1:
        return 1
    return n * factorial(n - 1)


t = int(input())

for _ in range(t):
    a, b = map(int, sys.stdin.readline().split())
    if a == b:
        print(1)
        continue
    maxN = max(a, b)
    minN = min(a, b)
    print(factorial(maxN) // (factorial(maxN - minN) * factorial(minN)))
