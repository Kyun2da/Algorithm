import sys

a,b = map(int,sys.stdin.readline().split())

if b>=45:
    b= b-45
    print("%d %d"%(a,b))
else:
    a = a-1
    b = b+15
    if a==-1:
        print("%d %d"%(23,b))
    else:
        print("%d %d"%(a,b))