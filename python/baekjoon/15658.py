n = int(input())
num = list(map(int, input().split()))
operator = list(map(int, input().split()))

maxAns = float('-inf')
minAns = float('inf')


def dfs(idx, arr, total):
    global maxAns, minAns, num
    if idx == n - 1:
        maxAns = max(maxAns, total)
        minAns = min(minAns, total)
        return
    for i in range(4):
        if arr[i] == 0: continue
        arr[i] -= 1
        if i == 0:
            dfs(idx + 1, arr, total + num[idx + 1])
        elif i == 1:
            dfs(idx + 1, arr, total - num[idx + 1])
        elif i == 2:
            dfs(idx + 1, arr, total * num[idx + 1])
        else:
            if total < 0 and num[idx + 1] > 0:
                dfs(idx + 1, arr, abs(total) // num[idx + 1] * -1)
            else:
                dfs(idx + 1, arr, total // num[idx + 1])
        arr[i] += 1


dfs(0, operator, num[0])

print(maxAns)
print(minAns)
