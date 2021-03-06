n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()


def dfs(vis):
    if len(vis) == m:
        print(' '.join(map(str, vis)))
        return
    overlap = 0
    for i in range(n):
        if overlap == arr[i] or len(vis) > 0 and vis[-1] > arr[i]: continue
        overlap = arr[i]
        vis.append(arr[i])
        dfs(vis)
        vis.pop()


dfs([])
