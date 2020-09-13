import sys
from collections import deque

n, k = map(int, input().split())

q = deque()
q.append(n)

count = 0
flag = False
arr = [0] * 100001
if n == k:
    print(0)
    exit()

while q:
    count += 1
    # print(q)
    for _ in range(len(q)):
        x = q.popleft()
        if x + 1 <= 100000 and arr[x + 1] == 0:
            q.append(x + 1)
            arr[x + 1] = 1
        if x * 2 <= 100000 and arr[x * 2] == 0:
            q.append(x * 2)
            arr[x * 2] = 1
        if x - 1 >= 0 and arr[x - 1] == 0:
            q.append(x - 1)
            arr[x - 1] = 1

        if x + 1 == k or x - 1 == k or x * 2 == k:
            flag = True
            break
    if flag:
        print(count)
        break
