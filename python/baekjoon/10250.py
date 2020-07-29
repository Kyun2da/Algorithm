num = int(input())

for i in range(num):
    H,W,N = map(int,input().split())
    a = N%H
    b = N//H +1
    if a==0:
        b-=1
        a = H
    print("%d%02d"%(a,b))

