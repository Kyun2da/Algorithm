import sys
from collections import deque

input = sys.stdin.readline

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
n, m = map(int, input().split())
visited = [[False] * m for _ in range(n)]
board = [list(map(int, input().split())) for _ in range(n)]
answer = 0


# 바깥 공기를 -1로 초기화
def outSide():
    q = deque()
    out_visited = [[False] * m for _ in range(n)]
    q.append((0, 0))
    out_visited[0][0] = True
    board[0][0] = -1
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny = dy[i] + y
            nx = dx[i] + x
            if 0 > ny or ny >= n or 0 > nx or nx >= m: continue
            if board[ny][nx] == 1 or out_visited[ny][nx]: continue
            q.append((ny, nx))
            board[ny][nx] = -1
            out_visited[ny][nx] = True
    return


# 치즈가 다 녹았는지 확인
def isMelt():
    for i in range(n):
        for j in range(m):
            if board[i][j] == 1:
                return False
    return True


while not isMelt():
    outSide()
    check = []
    for i in range(n):
        for j in range(m):
            if board[i][j] == 1:
                cnt = 0  # 바깥 공기와 맞닿은 칸의 개수
                for k in range(4):
                    ny = dy[k] + i
                    nx = dx[k] + j
                    if 0 > ny or ny >= n or 0 > nx or nx >= m: continue
                    if board[ny][nx] == -1:
                        cnt += 1
                if cnt >= 2:
                    check.append([i, j])
    for y, x in check:
        board[y][x] = 0
    answer += 1

print(answer)
