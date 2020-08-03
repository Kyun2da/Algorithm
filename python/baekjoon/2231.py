N = int(input())

ans = 0
for i in range(1,N):
    temp =i
    sum = i
    while temp!=0:
        sum += temp%10
        temp //= 10
    if sum==N:
        ans = i
        break

print(ans)