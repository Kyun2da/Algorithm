def gcd(a, b):
    while b > 0:
        tmp = b
        b = a % b
        a = tmp
    return a


N = int(input())

arr = list(map(int, input().split()))
for x in arr[1:]:
    tmp = gcd(arr[0],x)
    print("%d/%d"%(arr[0]/tmp,x/tmp))