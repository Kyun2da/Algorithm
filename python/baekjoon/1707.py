import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline


def dfs(now, group):
    vis[now] = group
    for i in arr[now]:
        # 아직 안가본 곳이면 방문
        if vis[i] == 0:
            if not dfs(i, -group):
                return False
        # 방문한 곳인데 색깔이 다르면 취소
        elif vis[i] == vis[now]:
            return False
    return True


for _ in range(int(input())):
    v, e = map(int, input().split())
    arr = [[] for _ in range(v + 1)]
    vis = [0] * (v + 1)
    for _ in range(e):
        x, y = map(int, input().split())
        arr[x].append(y)
        arr[y].append(x)
    ans = True
    for i in range(1, v + 1):
        if vis[i] == 0:
            ans = dfs(i, 1)
            if not ans:
                break
    print("YES" if ans else "NO")
