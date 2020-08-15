import sys

N = int(sys.stdin.readline())
arr = list(map(int,sys.stdin.readline().split()))

ldp = [1 for _ in range(N)]
rdp = [1 for _ in range(N)]

for i in range(1,len(arr)):
    for j in range(i):
        if arr[i]>arr[j]:
            ldp[i]=max(ldp[i],ldp[j]+1)

for i in range(len(arr)-2,-1,-1):
    for j in range(len(arr)-1,i,-1):
        if arr[i]>arr[j]:
            rdp[i]=max(rdp[i],rdp[j]+1)

ans = 0
for i in range(N):
    tmp = ldp[i]+rdp[i]-1
    if ans < tmp:
        ans = tmp

print(ans)