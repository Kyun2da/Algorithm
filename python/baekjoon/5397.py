from collections import deque

t = int(input())

for _ in range(t):
    ans = ""
    arr = list(map(str, input()))
    l, r = deque(), deque()
    for s in arr:
        if s == '<':
            if l:
                r.appendleft(l.pop())
        elif s == '>':
            if r:
                l.append(r.popleft())
        elif s == '-':
            if l:
                l.pop()
        else:
            l.append(s)
    l.extend(r)
    print(''.join(l))
