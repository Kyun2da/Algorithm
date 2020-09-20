n = int(input())

arr = []
ans = 0
for i in range(1, 10):
    arr.append(9 * i * (10 ** (i - 1)))

for i in range(len(str(n)) - 1):
    ans += arr[i]

ans += (n - 10 ** (len(str(n)) - 1)+1) * len(str(n))

print(ans)
