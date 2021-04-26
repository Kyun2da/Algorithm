import sys

a, b = map(str, input().split())

ans = sys.maxsize
for i in range(len(b) - len(a) + 1):
    tmp = 0
    for j in range(len(a)):
        if a[j] != b[j + i]:
            tmp += 1

    ans = min(ans, tmp)

print(ans)
