import sys

N,K = map(int,input().split())

arr = []
for _ in range(N):
    arr.append(int(input()))

ans = 0
idx = -1
while K!=0:
    ans+=K//arr[idx]
    K=K%arr[idx]
    idx-=1

print(ans)