import sys

n = int(input())

time = [0]
price = [0]

ans = 0
for _ in range(n):
    t, p = map(int, sys.stdin.readline().split())
    time.append(t)
    price.append(p)


def dfs(day, total):
    global ans
    # 날짜가 지났거나 일을할수없는 날짜면 끝낸다.
    if day > n or day + time[day]-1 > n:
        #print(total)
        ans = max(total, ans)
        return
    # 오늘이 일할수 있는 마지막 날이면 끝내고 답비교
    elif day+time[day]-1==n:
        ans = max(total+price[day],ans)
        return
    for i in range(day + time[day], n+1):
        dfs(i, total + price[day])


for i in range(1, n + 1):
    dfs(i, 0)

print(ans)