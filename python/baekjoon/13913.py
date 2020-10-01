import sys
from collections import deque

n, k = map(int, input().split())

vis = [-1] * 200001
q = deque([n])
vis[n] = 0
loc = [-1] * 200001
history = []

while q:
    x = q.popleft()
    if x == k:
        idx = x
        history.append(x)
        while loc[idx] != -1:
            history.append(loc[idx])
            idx = loc[idx]
        print(vis[x])
        print(' '.join(map(str, reversed(history))))
        sys.exit()
    if x - 1 >= 0 and vis[x - 1] == -1:
        q.append(x - 1)
        vis[x - 1] = vis[x] + 1
        loc[x - 1] = x
    if x + 1 <= 200000 and vis[x + 1] == -1:
        q.append(x + 1)
        vis[x + 1] = vis[x] + 1
        loc[x + 1] = x
    if x * 2 <= 200000 and vis[x * 2] == -1:
        q.append(x * 2)
        vis[x * 2] = vis[x] + 1
        loc[x * 2] = x
