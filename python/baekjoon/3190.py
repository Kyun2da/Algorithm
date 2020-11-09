import sys
from collections import deque

input = sys.stdin.readline

x, y = 0, 0
vis = deque([[0, 0]])
# 동 :0 서: 1 남: 2 북: 3 순서
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
# 보는 방향 처음에 동쪽보고있음
look = 0
# [동서남북][오른쪽왼쪽]배열
direction = [[2, 3], [3, 2], [1, 0], [0, 1]]
n = int(input())
k = int(input())

arr = [[0] * n for _ in range(n)]
arr[0][0] = 2
for _ in range(k):
    a, b = map(int, input().split())
    arr[a - 1][b - 1] = 1

l = int(input())
q = deque()
for _ in range(l):
    q.append(list(input().split()))

second = 1
comSecond, com = q.popleft()
while True:
    # 뱀 이동
    # 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
    x += dx[look]
    y += dy[look]
    if 0 <= x < n and 0 <= y < n and arr[x][y] != 2:
        if arr[x][y] != 1:
            tailx, taily = vis.popleft()
            arr[tailx][taily] = 0
        arr[x][y] = 2
        vis.append([x, y])
        # 정해진 초에 방향전황 명령어가 있으면 실행
        if int(comSecond) == second:
            if com == 'L':
                look = direction[look][1]
            else:
                look = direction[look][0]
            if q:
                comSecond, com = q.popleft()
        second += 1
        '''
        print('------------------------------')
        print('%d초' % second)
        for i in range(n):
            for j in range(n):
                print(arr[i][j], end=" ")
            print()
        '''
    else:
        print(second)
        break
