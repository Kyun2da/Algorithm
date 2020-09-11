import sys
sys.setrecursionlimit(10**6)

n, m = map(int, sys.stdin.readline().split())

arr = [[] for _ in range(n + 1)]
ans = 0
visited = [False] * (n + 1)

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    arr[a].append(b)
    arr[b].append(a)


def dfs(num):
    for i in arr[num]:
        if not visited[i]:
            visited[i]=True
            dfs(i)


for i in range(1, n + 1):
    if not visited[i]:
        dfs(i)
        ans += 1

print(ans)
