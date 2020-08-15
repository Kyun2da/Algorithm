import sys

N = int(sys.stdin.readline())
arr = list(map(int,sys.stdin.readline().split()))
dp = [1 for _ in range(len(arr))]

for i in range(1,len(arr)):
    for j in range(0,i):
        if arr[j]<arr[i]:
            dp[i] = max(dp[i],dp[j]+1)

print(max(dp))