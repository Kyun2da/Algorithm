N, M = map(int,input().split())

arr = [0 for _ in range(M)]

def dfs(index):
    if index==M:
        for i in arr:
            print(i, end=" ")
        print()
        return
    for i in range(1,N+1):
        if arr[index-1]>i:
            continue
        arr[index]=i
        dfs(index+1)
        arr[index]=0

dfs(0)