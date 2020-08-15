import sys

N = int(input())

arr = []
for _ in range(N):
    arr.append(list(map(int,sys.stdin.readline().split())))

arr.sort()
dp = [1 for _ in range(N)]
for i in range(1,N):
    for j in range(0,i):
        if (arr[i][0] > arr[j][0] and arr[i][1] < arr[j][1]) or (arr[i][0] < arr[j][0] and arr[i][1] > arr[j][1]):
            continue
        dp[i]=max(dp[j]+1,dp[i])

print(N-max(dp))