n = int(input())
a = int(input())

left = 1
right = a

while left <= right:
    cnt = 0
    mid = (left + right) // 2
    for i in range(1, n + 1):
        cnt += min(mid // i, n)
    if cnt < a:
        left = mid + 1
    else:
        ans = mid
        right = mid - 1

print(ans)
