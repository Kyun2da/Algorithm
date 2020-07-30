arr = list(map(int,input().split()))

sum=0
for i in arr:
    sum+=pow(i,2)

print(sum%10)