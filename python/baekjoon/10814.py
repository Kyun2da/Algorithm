N = int(input())

arr = []

for i in range(N):
    age, name = map(str,input().split())
    arr.append([int(age),name])

arr.sort(key = lambda x: x[0])

for item in arr:
    print("%d %s"%(item[0],item[1]))