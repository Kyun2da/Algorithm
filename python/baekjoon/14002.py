from collections import deque

n = int(input())

arr = list(map(int, input().split()))
dp = [0] * n
v = [0] * n
ans = deque()
maxNum = float('-inf')
maxIdx = 0
for i in range(0, n):
    dp[i] = 1
    v[i] = i
    for j in range(0, i):
        if dp[i] < dp[j] + 1 and arr[i] > arr[j]:
            dp[i] = dp[j] + 1
            v[i] = j
    if maxNum < dp[i]:
        maxIdx = i
        maxNum = dp[i]

idx = maxIdx
for _ in range(maxNum):
    ans.appendleft(arr[idx])
    idx = v[idx]

# print(dp)
# print(v)

print(maxNum)
for x in ans:
    print(x, end=" ")
