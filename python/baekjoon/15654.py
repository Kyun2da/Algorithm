n, m = map(int, input().split())
arr = list(map(int, input().split()))
tmpArr = []

arr.sort()


def dfs(tmpArr):
    if len(tmpArr) == m:
        print(" ".join(map(str, tmpArr)))
        return

    for i in range(n):
        if arr[i] in tmpArr: continue
        tmpArr.append(arr[i])
        dfs(tmpArr)
        tmpArr.pop()


dfs(tmpArr)
