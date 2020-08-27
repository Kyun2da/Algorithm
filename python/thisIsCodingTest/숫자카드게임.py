N, M = map(int,input().split())

arr = []
for _ in range(N):
    arr.append(list(map(int,input().split())))

minList = []
for i in range(N):
    minList.append(min(arr[i]))

print(max(minList))