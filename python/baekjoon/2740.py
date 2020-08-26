import sys

N, M = map(int, sys.stdin.readline().split())

arr1 = []
arr2 = []
for i in range(N):
    arr1.append(list(map(int, sys.stdin.readline().split())))

M, K = map(int, sys.stdin.readline().split())
for i in range(M):
    arr2.append(list(map(int, sys.stdin.readline().split())))

res = [[0] * K for i in range(N)]
for i in range(N):
    for j in range(K):
        for x in range(M):
            res[i][j] += arr1[i][x] * arr2[x][j]

for i in range(N):
    for j in range(K):
        print(res[i][j], end=" ")
    print()
