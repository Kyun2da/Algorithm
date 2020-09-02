n, m = map(int, input().split())

ans = 0
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]


# ㅗ 모양을 제외하고는 dfs로 해결가능함
def dfs(y, x, visited, num, blockSum):
    global ans
    if num == 4:
        if ans < blockSum:
            ans = blockSum
        return
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < n and 0 <= nx < m and not visited[ny][nx]:
            visited[ny][nx] = True
            dfs(ny, nx, visited, num + 1, blockSum + arr[ny][nx])
            visited[ny][nx] = False


def fuck(x, y):
    global ans
    sumVal = arr[x][y]

    if x == 0:
        if y == 0 or y == m - 1:
            return
    elif x == n - 1:
        if y == 0 or y == m - 1:
            return

    if x == 0:
        sumVal += arr[x + 1][y] + arr[x][y - 1] + arr[x][y + 1]
    elif x == n - 1:
        sumVal += arr[x - 1][y] + arr[x][y - 1] + arr[x][y + 1]
    elif y == 0:
        sumVal += arr[x][y + 1] + arr[x - 1][y] + arr[x + 1][y]
    elif y == m - 1:
        sumVal += arr[x][y - 1] + arr[x - 1][y] + arr[x + 1][y]
    else:
        sumlist = []
        sumlist.append(sumVal + arr[x + 1][y] + arr[x][y - 1] + arr[x][y + 1])
        sumlist.append(sumVal + arr[x - 1][y] + arr[x][y - 1] + arr[x][y + 1])
        sumlist.append(sumVal + arr[x][y + 1] + arr[x - 1][y] + arr[x + 1][y])
        sumlist.append(sumVal + arr[x][y - 1] + arr[x - 1][y] + arr[x + 1][y])
        sumVal = max(sumlist)

    if ans < sumVal:
        ans = sumVal


visited = [[False] * m for _ in range(n)]
for i in range(n):
    for j in range(m):
        fuck(i, j)
        visited[i][j] = True
        dfs(i, j, visited, 1, arr[i][j])
        visited[i][j] = False

print(ans)
