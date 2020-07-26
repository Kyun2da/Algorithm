num = int(input())
arr = list(map(int,input().split()))

arr.sort()

print("%d %d"%(arr[0],arr[-1]))
