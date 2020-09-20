'''
n, m = map(int, input().split())

arr = list(map(int, input().split()))
dp = [0] * (n + 1)
dp[0] = 0
ans = 0

for i in range(1, n + 1):
    dp[i] = dp[i - 1] + arr[i - 1]

# print(dp)
for i in range(0, n):
    for j in range(i + 1, n + 1):
        if dp[j] < m:
            continue
        if dp[j] - dp[i] == m:
            ans += 1
            break
            # print(i, j)
        if dp[j] - dp[i] > m:
            break

print(ans)
'''

# 투포인터
n, m = map(int, input().split())
arr = list(map(int, input().split()))

dp = [0] * (n + 1)
for i in range(1, n + 1):
    dp[i] = dp[i - 1] + arr[i - 1]

# 투포인터 설정
start = 0
end = 1
ans = 0

while start != n:
    # 부분합의 크기가 m보다 크거나 같을경우
    # print(start,end)
    if dp[end] - dp[start] >= m:
        if dp[end] - dp[start] == m:
            ans += 1
        start += 1

    else:
        if end < n:
            end += 1
        else:
            start += 1

# 답이 없을 경우 & 있을 경우
print(ans)
