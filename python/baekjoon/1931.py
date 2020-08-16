import sys

N = int(input())

arr = []
for _ in range(N):
    arr.append(list(map(int,sys.stdin.readline().split())))

arr.sort(key=lambda x: (x[1],x[0]))


ans = 1
tmp = arr[0][1]
for i in range(1,len(arr)):
    if arr[i][0] < tmp: continue
    tmp = arr[i][1]
    ans+=1

print(ans)