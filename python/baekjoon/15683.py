import sys
import copy

input = sys.stdin.readline

n, m = map(int, input().split())

arr = list(list(map(int, input().split())) for _ in range(n))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
pos = [0, [[0], [1], [2], [3]], [[0, 1], [2, 3]], [[1, 2], [1, 3], [0, 2], [0, 3]],
       [[0, 1, 2], [0, 1, 3], [0, 2, 3], [1, 2, 3]], [[0, 1, 2, 3]]]
cctv = []
ans = 1e9
# cctv 배열에 cctv 넣기
for i in range(n):
    for j in range(m):
        if arr[i][j] not in [0, 6]:
            cctv.append([arr[i][j], i, j])


def dfs(num, tarr, tcctv):
    global ans
    if num == len(tcctv):
        cnt = 0
        for i in range(n):
            for j in range(m):
                if tarr[i][j] == 0:
                    cnt += 1
        ans = min(ans, cnt)
        return

    cnum, x, y = cctv[num]
    for i in pos[cnum]:
        tmp = copy.deepcopy(tarr)
        for j in i:
            nx, ny = x + dx[j], y + dy[j]
            while 0 <= nx < n and 0 <= ny < m:
                if tmp[nx][ny] == 6:
                    break
                elif tmp[nx][ny] == 0:
                    tmp[nx][ny] = '#'
                nx += dx[j]
                ny += dy[j]
        dfs(num + 1, tmp, cctv)


dfs(0, arr, cctv)
print(ans)