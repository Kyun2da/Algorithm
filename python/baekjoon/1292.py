a, b = map(int, input().split())

num = 1
count = 0
ans = 0

for i in range(1, 1001):
    if a <= i <= b:
        ans += num

    count += 1
    if num == count:
        num += 1
        count = 0

print(ans)
