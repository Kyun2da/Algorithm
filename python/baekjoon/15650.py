N, M = map(int,input().split())

arr = [0 for i in range(M)]
check = [False for i in range(N+1)]

def dfs(index):
    if index==M:
        for i in range(M):
            print(arr[i], end=" ")
        print()
        return
    for i in range(1,N+1):
        if check[i] or (index>0 and arr[index-1]>i):
            continue
        check[i]=True
        arr[index]=i
        dfs(index+1)
        check[i]=False

dfs(0)