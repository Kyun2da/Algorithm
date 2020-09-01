import sys
import math

n = int(input())

for _ in range(n):
    arr = list(map(int, sys.stdin.readline().rstrip().split()))
    num = 0
    ans = []
    for i in range(1, len(arr) - 1):
        for j in range(i+1, len(arr)):
            ans.append(math.gcd(arr[i], arr[j]))

    print(sum(ans))
