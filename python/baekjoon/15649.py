N, M = map(int,input().split())

check = [False for i in range(N+1)]
arr = [0 for i in range(M)]

def dfs(index):
    if index==M:
        for i in range(M):
            print(arr[i],end=" ")
        print()
        return
    for i in range(1,N+1):
        if check[i]:
            continue
        check[i]=True
        arr[index] = i
        dfs(index+1)
        check[i]=False

dfs(0)

#permutation 사용가능!
# import itertools
#
# N, M = map(int, input().split())
# pool = map(str, range(1, N+1))
# print("\n".join(list(map(' '.join, itertools.permutations(pool, M)))))