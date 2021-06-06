import sys
from bisect import bisect_left

input = sys.stdin.readline

n = int(input())

arr = [0] + list(map(int,input().split()))
dp = [0] *(n+1)
cmp = [-1000000001]
maxVal = 0

for i in range(1, n+1):
    if cmp[-1] < arr[i]:
        cmp.append(arr[i])
        dp[i] = len(cmp) -1
        maxVal = dp[i]
    else:
        dp[i] = bisect_left(cmp, arr[i])
        cmp[dp[i]] = arr[i]

print(maxVal)

res = []
for i in range(n,0,-1):
    if dp[i] == maxVal:
        res.append(arr[i])
        maxVal -=1
res.reverse()
print(*res)