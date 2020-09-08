n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()


def dfs(vis):
    if len(vis) == m:
        for i in range(m):
            print(arr[vis[i]], end=" ")
        print()
        return
    overlap = 0
    for i in range(n):
        if overlap == arr[i] or (len(vis) > 0 and vis[-1] >= i): continue
        overlap = arr[i]
        vis.append(i)
        dfs(vis)
        vis.pop()


dfs([])
