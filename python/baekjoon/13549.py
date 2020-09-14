import sys
from collections import deque

n, k = map(int, input().split())

q = deque()
vis = [-1] * 200001
q.append(n)
vis[n] = 0

while q:
    x = q.popleft()
    if x == k:
        print(vis[x])
        sys.exit()
    # 순간이동해서 갈수 있는곳을 구한다.
    if x * 2 <= 200000 and vis[x * 2] == -1:
        vis[x * 2] = vis[x]
        q.appendleft(x * 2)
    # x-1 로 갈수 있는곳 1초 더한다.
    if x - 1 >= 0 and vis[x - 1] == -1:
        vis[x - 1] = vis[x] + 1
        q.append(x - 1)
    # x+1 로 갈 수 있는곳 1초 더한다.
    if x + 1 <= 200000 and vis[x + 1] == -1:
        vis[x + 1] = vis[x] + 1
        q.append(x + 1)
