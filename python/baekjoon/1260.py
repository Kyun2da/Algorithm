import sys
from collections import deque

n, m, v = map(int, input().split())

arr = [[] for _ in range(n + 1)]
dfsAns = []
bfsAns = []

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    arr[a].append(b)
    arr[b].append(a)

# 인접 리스트 정렬
for i in range(n):
    arr[i].sort()


def dfs(idx):
    for i in arr[idx]:
        if i not in dfsAns:
            dfsAns.append(i)
            dfs(i)


def bfs(idx):
    q = deque([idx])
    while q:
        n = q.popleft()
        if n not in bfsAns:
            bfsAns.append(n)
            for i in arr[n]:
                if i not in bfsAns:
                    q.append(i)


dfsAns.append(v)
dfs(v)
bfs(v)

print(' '.join(map(str, dfsAns)))
print(' '.join(map(str, bfsAns)))
