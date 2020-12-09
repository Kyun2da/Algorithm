import sys
from collections import deque


def bfs(p1, p2):
    count = 0
    q = deque()
    q.append([p1, count])
    while q:
        tmp, count = q.popleft()
        if tmp == p2:
            return count
        if not vis[tmp]:
            count += 1
            vis[tmp] = True
            for e in adj[tmp]:
                if not vis[e]:
                    q.append([e, count])
    return -1


n = int(sys.stdin.readline())

adj = [[] for _ in range(n + 1)]
vis = [False] * (n + 1)
person1, person2 = map(int, sys.stdin.readline().split())
m = int(sys.stdin.readline())
ans = 0

for _ in range(m):
    x, y = map(int, sys.stdin.readline().split())
    adj[x].append(y)
    adj[y].append(x)

print(bfs(person1, person2))
