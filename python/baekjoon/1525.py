from collections import deque

arr = []

for i in range(3):
    arr.append(list(map(int, input().split())))

x = []
s = ''
# arr를 string으로 만들고, 0을 9로 변환
for i in range(3):
    for j in range(3):
        if arr[i][j] == 0:
            arr[i][j] = 9
        s += str(arr[i][j])

q = deque([int(s)])
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
vis = dict()
vis[int(s)] = 0

while q:
    s = q.popleft()
    if s == 123456789:
        print(vis[s])
        exit()

    k = str(s).find('9')
    x, y = k // 3, k % 3
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < 3 and 0 <= ny < 3:
            nk = nx * 3 + ny
            ns = list(str(s))
            ns[k], ns[nk] = ns[nk], ns[k]
            nd = int(''.join(ns))

            if not vis.get(nd):
                vis[nd] = vis[s] + 1
                q.append(nd)

print(-1)