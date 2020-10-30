import math

n = int(input())
arr = list(map(int, input().split()))
b, c = map(int, input().split())

ans = len(arr)
for i in range(len(arr)):
    if arr[i] - b > 0:
        ans += math.ceil((arr[i] - b) / c)

print(ans)
