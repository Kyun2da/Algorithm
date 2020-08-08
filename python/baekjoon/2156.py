import sys

N = int(sys.stdin.readline())

arr = [0]

for _ in range(N):
    arr.append(int(sys.stdin.readline()))

dp = [0 for i in range(N+1)]
dp[1] = arr[1]
if N>=2:
    dp[2] = arr[1]+arr[2]

for i in range(3,N+1):
    dp[i]=max(dp[i-1],dp[i-3]+arr[i]+arr[i-1],dp[i-2]+arr[i])

print(dp[N])