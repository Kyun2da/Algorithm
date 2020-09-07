from itertools import combinations

n, s = map(int, input().split())

ans = 0
arr = list(map(int, input().split()))

for i in range(1, n + 1):
    for x in combinations(arr, i):
        if sum(x) == s:
            ans += 1

print(ans)
