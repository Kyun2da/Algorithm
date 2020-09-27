import math

n = 4_000_000
arr = [True for _ in range(n + 1)]

for i in range(2, int(math.sqrt(n)) + 1):
    if arr[i]:
        j = 2
        while i * j <= n:
            arr[i * j] = False
            j += 1

k = int(input())
if k == 1:
    print(0)
    exit()

sosu = []
for i in range(2, k + 1):
    if arr[i]:
        sosu.append(i)

ans = 0
end = 0
sumA = sosu[0]
length = len(sosu)
for start in sosu:
    while sumA < k and end < length:
        end += 1
        if end == length:
            break
        sumA += sosu[end]
    if sumA == k:
        ans += 1
    sumA -= start

print(ans)
