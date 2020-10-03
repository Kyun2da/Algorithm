from collections import deque

n, k = map(int, input().split())

q = deque([n])
vis = [False] * 100001
ans = -1
count = 0

while q:
    ans += 1
    check = []
    for i in range(len(q)):
        x = q.popleft()
        if x == k:
            count += 1
        if x != 0 and not vis[x - 1]:
            q.append(x - 1)
            check.append(x - 1)
        if x != 100000 and not vis[x + 1]:
            q.append(x + 1)
            check.append(x + 1)
        if 0 <= x <= 50000 and not vis[x * 2]:
            q.append(x * 2)
            check.append(x * 2)
    for i in check:
        vis[i] = True
    if count != 0:
        break

print(ans)
print(count)
