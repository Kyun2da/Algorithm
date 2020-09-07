import sys

n = int(input())

s = set()

for _ in range(n):
    com = sys.stdin.readline().split()

    if len(com) == 1:
        if com[0] == 'all':
            s = set([i for i in range(1, 21)])
        else:
            s = set()
        continue

    com, num = com[0], int(com[1])

    if com == 'add':
        s.add(num)
    elif com == 'remove':
        s.discard(num)
    elif com == 'check':
        if num in s:
            print(1)
        else:
            print(0)
    elif com == 'toggle':
        if num in s:
            s.discard(num)
        else:
            s.add(num)
