n = int(input())

ans = 0
for _ in range(n):
    if int(input()) == 1:
        ans += 1
    else:
        ans -= 1

if ans > 0:
    print("Junhee is cute!")
else:
    print("Junhee is not cute!")
