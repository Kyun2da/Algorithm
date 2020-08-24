from collections import deque

import sys

N, K = map(int, sys.stdin.readline().split())

deq = deque([i for i in range(1, N + 1)])
ans = []

while len(deq) != 0:
    for _ in range(K - 1):
        num = deq.popleft()
        deq.append(num)
    ans.append(deq.popleft())

print('<', end="")
for x in ans:
    print(x, end="")
    if x != ans[-1]:
        print(", ", end="")
print('>', end="")
