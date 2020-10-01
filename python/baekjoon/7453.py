import sys

n = int(input())

arrA, arrB, arrC, arrD = [], [], [], []

for _ in range(n):
    a, b, c, d = map(int, sys.stdin.readline().split())
    arrA.append(a)
    arrB.append(b)
    arrC.append(c)
    arrD.append(d)

ab, cd = {}, {}

for a in arrA:
    for b in arrB:
        if not ab.get(a + b):
            ab[a + b] = 1
        else:
            ab[a + b] += 1

for c in arrC:
    for d in arrD:
        if not cd.get(c + d):
            cd[c + d] = 1
        else:
            cd[c + d] += 1

ans = 0

for _, key in enumerate(ab):
    if cd.get(-key):
        ans += (ab[key] * cd[-key])

print(ans)
