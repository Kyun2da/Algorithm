N = int(input())

ans = 0
for i in range(2, N + 1):
    if i % 5 == 0: ans += 1
    if i % 25 == 0: ans += 1
    if i % 125 == 0: ans += 1

print(ans)