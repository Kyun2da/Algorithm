def dfs(num, total, strAns):
    global minAns, maxAns
    if total == n:
        # print(strAns)
        if int(minAns) > int(strAns):
            minAns = strAns
        if int(maxAns) < int(strAns):
            maxAns = strAns
        return
    for i in range(0, 10):
        if vis[i]: continue
        if arr[total] == '<':
            if num < i:
                vis[i] = True
                dfs(i, total + 1, strAns + str(i))
                vis[i] = False
        else:
            if num > i:
                vis[i] = True
                dfs(i, total + 1, strAns + str(i))
                vis[i] = False


n = int(input())

arr = list(map(str, input().split()))
minAns = 9999999999
maxAns = 0
vis = [False] * 10

for i in range(0, 10):
    vis[i] = True
    dfs(i, 0, str(i))
    vis[i] = False

print(maxAns)
print(minAns)
