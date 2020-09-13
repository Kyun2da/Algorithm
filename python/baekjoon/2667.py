import sys

n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(int, str(sys.stdin.readline().rstrip()))))


def dfs(i, j):
    global num

    if arr[i][j] == 1:
        arr[i][j] = 2
        num += 1
    if j + 1 < n and arr[i][j + 1] == 1:
        dfs(i, j + 1)
    if i + 1 < n and arr[i + 1][j] == 1:
        dfs(i + 1, j)
    if i - 1 >= 0 and arr[i - 1][j] == 1:
        dfs(i - 1, j)
    if j - 1 >= 0 and arr[i][j - 1] == 1:
        dfs(i, j - 1)


numarr = []

for i in range(n):
    for j in range(n):
        num = 0
        if arr[i][j] == 1:
            dfs(i, j)
            numarr.append(num)

numarr.sort()
print(len(numarr))
print('\n'.join(map(str, numarr)))
