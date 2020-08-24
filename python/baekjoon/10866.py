from collections import deque

import sys

N = int(input())
deq = deque()
for _ in range(N):
    command = sys.stdin.readline().rstrip()
    if command.split()[0]=='push_front':
        deq.appendleft(int(command.split()[1]))
    elif command.split()[0]=='push_back':
        deq.append(int(command.split()[1]))
    elif command == 'pop_front':
        if len(deq)==0:
            print(-1)
        else:
            num = deq.popleft()
            print(num)
    elif command == 'pop_back':
        if len(deq)==0:
            print(-1)
        else:
            num = deq.pop()
            print(num)
    elif command=='size':
        print(len(deq))
    elif command == 'empty':
        if len(deq)==0:
            print(1)
        else:
            print(0)
    elif command == 'front':
        if len(deq)==0:
            print(-1)
        else:
            print(deq[0])
    elif command == 'back':
        if len(deq)==0:
            print(-1)
        else:
            print(deq[-1])