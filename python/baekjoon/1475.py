import math

n = list(str(input()))

ans = 0
arr = [0] * 10

for x in n:
    k = int(x)
    if k == 6:
        arr[9] += 1
    else:
        arr[k % 10] += 1

ans = 0
while sum(arr) != 0:
    for i in range(10):
        if i == 6 and arr[9] != 0:
            arr[9] -= 1
        elif arr[i] != 0:
            arr[i] -= 1
    ans += 1

print(ans)
