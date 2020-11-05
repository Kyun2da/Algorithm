n = int(input())
arr = list(map(int, input().split()))

ans = 0
for x in arr:
    if x % 10 == n:
        ans += 1
print(ans)
