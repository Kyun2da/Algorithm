n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
tmpArr = []


def dfs(vis):
    if len(vis) == m:
        print(' '.join(map(str, vis)))
        return
    for x in arr:
        if len(vis) != 0 and vis[-1] > x: continue
        vis.append(x)
        dfs(vis)
        vis.pop()


dfs(tmpArr)
