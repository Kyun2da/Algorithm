def d(n):
    res = n
    while n!=0:
        res+=n%10
        n=n//10
    return res

arr = [0 for i in range(10001)]

for i in range(1,10001):
    val = d(i)
    if val<=10000:
        arr[val] = 1

for i in range(1,10001):
    if arr[i]!=1:
        print(i)