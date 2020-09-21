import sys
from collections import deque

n, m = map(int, input().split())

arr = [list(sys.stdin.readline().rstrip()) for _ in range(n)]
c, q, cnt = [], deque(), 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# R과 B의 인덱스를 저장하고 .으로 변경
for i in range(n):
    for j in range(m):
        if arr[i][j] == 'R':
            rx, ry = i, j
            arr[i][j] = '.'
        elif arr[i][j] == 'B':
            bx, by = i, j
            arr[i][j] = '.'


def bfs(rx, ry, bx, by, cnt):
    q.append([rx, ry, bx, by])
    c.append([rx, ry, bx, by])
    while q:
        lenq = len(q)
        for _ in range(lenq):
            rx, ry, bx, by = q.popleft()
            if arr[rx][ry] == 'O':
                print(cnt)
                return
            for i in range(4):
                nrx, nry, nbx, nby = rx, ry, bx, by
                # #이 나올때까지 빨간색 이동
                while True:
                    nrx += dx[i]
                    nry += dy[i]
                    if arr[nrx][nry] == 'O':
                        break
                    if arr[nrx][nry] == '#':
                        nrx -= dx[i]
                        nry -= dy[i]
                        break
                # #이 나올때까지 파란색 이동
                while True:
                    nbx += dx[i]
                    nby += dy[i]
                    if arr[nbx][nby] == 'O':
                        break
                    if arr[nbx][nby] == '#':
                        nbx -= dx[i]
                        nby -= dy[i]
                        break

                # 파란색 구슬이 빠진경우 넘어간다.
                if arr[nbx][nby] == 'O':
                    continue
                # 빨간색 구슬과 파란색 구슬이 겹치면 서로의 위치를 보고 계산해줌
                if nrx == nbx and nry == nby:
                    if abs(rx - nrx) + abs(ry - nry) > abs(bx - nbx) + abs(by - nby):
                        nrx -= dx[i]
                        nry -= dy[i]
                    else:
                        nbx -= dx[i]
                        nby -= dy[i]

                if [nrx, nry, nbx, nby] not in c:
                    c.append([nrx, nry, nbx, nby])
                    q.append([nrx, nry, nbx, nby])

        if cnt == 10:
            print(-1)
            return
        cnt += 1
    print(-1)
    return


bfs(rx, ry, bx, by, cnt)
