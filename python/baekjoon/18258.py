from collections import deque

import sys

N = int(input())

deq = deque()

for _ in range(N):
    command = sys.stdin.readline().rstrip()
    if command.split()[0] == 'push':
        deq.append(int(command.split()[1]))
    elif command == 'pop':
        if len(deq) == 0:
            print(-1)
        else:
            print(deq[0])
            deq.popleft()
    elif command == 'size':
        print(len(deq))
    elif command == 'front':
        if len(deq) == 0:
            print(-1)
        else:
            print(deq[0])
    elif command == 'empty':
        if len(deq)==0:
            print(1)
        else:
            print(0)
    else:
        if len(deq) == 0:
            print(-1)
        else:
            print(deq[-1])
