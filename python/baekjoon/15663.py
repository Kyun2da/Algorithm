n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

tmpArr = []
visited = [False] * n


def dfs(vis):
    if len(vis) == m:
        print(' '.join(map(str, vis)))
        return
    overlap = 0
    for i in range(n):
        if not visited[i] and overlap != arr[i]:
            visited[i] = True
            vis.append(arr[i])
            overlap = arr[i]
            dfs(vis)
            visited[i] = False
            vis.pop()


dfs(tmpArr)
