N = int(input())

arr = []
for i in range(N):
    arr.append(list(map(int,input().split())))

arr.sort(key= lambda item: (item[1], item[0]))
for [i,j] in arr:
    print(i,j)