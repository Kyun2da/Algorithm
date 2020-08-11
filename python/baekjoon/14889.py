def dfs(index):
    global minAns
    if index == N // 2:
        # 계산 진행
        startSum = 0
        linkSum = 0
        for i in range(0,N):
            if i not in start:
                link.append(i)
        for i in range(0, N // 2 - 1):
            for j in range(i+1, N // 2):
                startSum += arr[start[i]][start[j]] + arr[start[j]][start[i]]
                linkSum += arr[link[i]][link[j]] + arr[link[j]][link[i]]
        diff = abs(linkSum-startSum)
        if minAns > diff:
            minAns = diff
        link.clear()
        return
    for i in range(N):
        if i in start: continue
        if len(start)>0 and start[len(start)-1]> i : continue
        start.append(i)
        dfs(index + 1)
        start.pop()


N = int(input())

arr = []
start = []
link = []
for i in range(N):
    arr.append(list(map(int, input().split())))

minAns = float('Inf')
dfs(0)
print(minAns)
