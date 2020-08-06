import sys

N = int(sys.stdin.readline())

arr = []
for _ in range(N):
    arr.append(list(map(int,sys.stdin.readline().split())))

for i in range(1,N):
    length = len(arr[i])
    for j in range(length):
        if j==0:
            arr[i][j]+=arr[i-1][j]
        elif j==length-1:
            arr[i][j]+=arr[i-1][j-1]
        else:
            arr[i][j]+=max(arr[i-1][j-1],arr[i-1][j])

print(max(arr[N-1]))