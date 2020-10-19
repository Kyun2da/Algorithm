ans = 0
people = 0
for _ in range(4):
    a, b = map(int, input().split())
    people += b - a
    ans = max(ans, people)

print(ans)
