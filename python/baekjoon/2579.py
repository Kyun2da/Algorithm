import sys

N = int(sys.stdin.readline())

arr = []

for _ in range(N):
    arr.append(int(sys.stdin.readline()))

if N==1:
    print(arr[0])
elif N==2:
    print(arr[0]+arr[1])
else:
    dp = [arr[0],arr[0]+arr[1],max(arr[0]+arr[2],arr[1]+arr[2])]
    for i in range(3,N):
        dp.append(max(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]))

    print(dp[N-1])