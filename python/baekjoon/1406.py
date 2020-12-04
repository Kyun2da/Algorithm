import sys

s1 = list(sys.stdin.readline().rstrip())
s2 = []

n = int(sys.stdin.readline().rstrip())

for _ in range(n):
    com = sys.stdin.readline().rstrip()
    if com == 'L':
        if s1: s2.append(s1.pop())
    elif com == 'D':
        if s2: s1.append(s2.pop())
    elif com == 'B':
        if s1: s1.pop()
    else:
        newS = com.split()[1]
        s1.append(newS)

print(''.join(s1 + list(reversed(s2))))
