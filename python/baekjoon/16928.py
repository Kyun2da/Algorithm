import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
snake_ladder = [0] * 101

for _ in range(n + m):
    a, b = map(int, input().split())
    snake_ladder[a] = b

q = deque()
q.append([1, 0])
vis = [0] * 101
ans = float('inf')

while q:
    pos, count = q.popleft()

    if pos == 100:
        ans = min(ans, count)

    for i in range(1, 7):
        new_pos = pos + i
        if new_pos > 100:
            break
        if vis[new_pos]:
            continue
        vis[new_pos] = True

        if snake_ladder[new_pos] != 0:
            new_pos = snake_ladder[new_pos]

        q.append([new_pos, count + 1])

print(ans)
