n = int(input())

m = int(input())
if m != 0:
    arr = list(map(int, input().split()))
else:
    arr = []
num = 100

ans = abs(n - 100)
for i in range(1000001):
    numArr = list(str(i))
    flag = False
    for k in numArr:
        if int(k) in arr:
            flag = True
            break

    if flag:
        continue
    else:
        ans = min(ans, abs(n - i) + len(str(i)))

print(ans)
