from collections import deque

a, b = map(int, input().split())
maxSize = 10 ** 9 + 1

q = deque()
q.append(a)
count = 0
ans = -1

while q:
    length = len(q)
    count += 1
    for _ in range(length):
        x = q.popleft()
        if x == b:
            ans = count
            break

        if x * 2 < maxSize:
            q.append(x * 2)

        appendOne = int(str(x) + '1')
        if appendOne < maxSize:
            q.append(appendOne)

print(ans)
