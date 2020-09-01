import sys
from collections import deque

n = int(input())

deq = deque()

for _ in range(n):
    com = sys.stdin.readline().rstrip()
    if com.split()[0] == 'push':
        deq.append(com.split()[1])
    elif com == 'pop':
        if len(deq):
            print(deq.popleft())
        else:
            print(-1)
    elif com == 'size':
        print(len(deq))
    elif com == 'empty':
        if len(deq) == 0:
            print(1)
        else:
            print(0)
    elif com == 'front':
        if len(deq):
            print(deq[0])
        else:
            print(-1)
    elif com == 'back':
        if len(deq):
            print(deq[-1])
        else:
            print(-1)
