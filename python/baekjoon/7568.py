N = int(input())

arr= []
rank = []

for i in range(N):
    x,y = map(int,input().split())
    arr.append([x,y])

for i in range(N):
    temp = 1
    for j in range(N):
        if arr[j][0]>arr[i][0] and arr[j][1]>arr[i][1]:
            temp+=1
    rank.append(temp)

for i in range(N):
    print(rank[i],end=" ")