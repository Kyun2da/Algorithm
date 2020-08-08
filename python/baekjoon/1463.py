#X가 3으로 나누어 떨어지면, 3으로 나눈다.
#X가 2로 나누어 떨어지면, 2로 나눈다.
#1을 뺀다.

import sys

N = int(sys.stdin.readline())

dp = [0,0]

for i in range(2,N+1):
    if i%6 == 0:
        dp.append(min(dp[i-1],dp[i//2],dp[i//3])+1)
    elif i%3 ==0:
        dp.append(min(dp[i-1],dp[i//3])+1)
    elif i%2 ==0:
        dp.append(min(dp[i-1],dp[i//2])+1)
    else:
        dp.append(dp[i-1]+1)

print(dp[N])