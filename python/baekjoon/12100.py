import sys
import copy

n = int(input())

arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
ans = 0
#print(arr)


def move(idx):
    # 0부터 3까지 상,하,좌,우 를 의미
    if idx == 0:
        for j in range(n):
            idx = 0
            for i in range(1, n):
                if arr[i][j]:
                    temp = arr[i][j]
                    arr[i][j] = 0
                    if arr[idx][j] == 0:
                        arr[idx][j] = temp
                    elif arr[idx][j] == temp:
                        arr[idx][j] = temp * 2
                        idx += 1
                    else:
                        idx += 1
                        arr[idx][j] = temp
    elif idx == 1:
        for j in range(n):
            idx = n - 1
            for i in range(n - 2, -1, -1):
                if arr[i][j]:
                    temp = arr[i][j]
                    arr[i][j] = 0
                    if arr[idx][j] == 0:
                        arr[idx][j] = temp
                    elif arr[idx][j] == temp:
                        arr[idx][j] = temp * 2
                        idx -= 1
                    else:
                        idx -= 1
                        arr[idx][j] = temp

    elif idx == 2:
        for i in range(n):
            idx = 0
            for j in range(1, n):
                if arr[i][j]:
                    temp = arr[i][j]
                    arr[i][j] = 0
                    if arr[i][idx] == 0:
                        arr[i][idx] = temp
                    elif arr[i][idx] == temp:
                        arr[i][idx] = temp * 2
                        idx += 1
                    else:
                        idx += 1
                        arr[i][idx] = temp

    else:
        for i in range(n):
            idx = n - 1
            for j in range(n - 2, -1, -1):
                if arr[i][j]:
                    temp = arr[i][j]
                    arr[i][j] = 0
                    if arr[i][idx] == 0:
                        arr[i][idx] = temp
                    elif arr[i][idx] == temp:
                        arr[i][idx] = temp * 2
                        idx -= 1
                    else:
                        idx -= 1
                        arr[i][idx] = temp


def dfs(count):
    global ans, arr
    if count == 5:
        for i in range(n):
            ans = max(ans, max(arr[i]))
        return

    tmp = copy.deepcopy(arr)
    for i in range(4):
        move(i)
        dfs(count + 1)
        arr = copy.deepcopy(tmp)


dfs(0)
print(ans)
