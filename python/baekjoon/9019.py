from collections import deque

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    vis = ['X'] * 10000
    com = [0] * 10000
    q = deque([a])
    ans = []
    while q:
        x = q.popleft()
        # print(x)
        # D n*2
        if x == b:
            while x != a:
                ans.append(vis[x])
                x = com[x]
            print(''.join(map(str, reversed(ans))))
            break
        if x * 2 > 9999:
            if vis[x * 2 % 10000] == 'X':
                q.append(x * 2 % 10000)
                vis[x * 2 % 10000] = 'D'
                com[x * 2 % 10000] = x
        else:
            if vis[x * 2] == 'X':
                q.append(x * 2)
                vis[x * 2] = 'D'
                com[x * 2] = x
        # S n-1
        if x == 0 and vis[9999] == 'X':
            vis[9999] = 'S'
            q.append(9999)
            com[9999] = x
        elif x != 0 and vis[x - 1] == 'X':
            vis[x - 1] = 'S'
            q.append(x - 1)
            com[x - 1] = x
        # L 왼쪽회전
        strx = '0' * (4-len(str(x))) + str(x)
        lnum = int(strx[1:] + strx[0])
        if vis[lnum] == 'X':
            vis[lnum] = 'L'
            q.append(lnum)
            com[lnum] = x
        # R 오른쪽회전
        rnum = int(strx[-1] + strx[:-1])
        if vis[rnum] == 'X':
            vis[rnum] = 'R'
            q.append(rnum)
            com[rnum] = x
