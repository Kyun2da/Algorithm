import math
import sys

n = int(input())

for _ in range(n):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    print(a * b // math.gcd(a, b))
