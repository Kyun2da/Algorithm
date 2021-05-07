import sys
from collections import deque

input = sys.stdin.readline


def spring_and_summer():
    for i in range(n):
        for j in range(n):
            length = len(trees[i][j])
            for k in range(length):
                # 봄에는 나무가 양분을 먹고 나이 증가
                if trees[i][j][k] <= land[i][j]:
                    land[i][j] -= trees[i][j][k]
                    trees[i][j][k] += 1
                # 여름에는 봄에 죽은 나무가 양분으로 변함
                else:
                    for _ in range(k, length):
                        land[i][j] += trees[i][j].pop() // 2
                    break


def fall_and_winter():
    for i in range(n):
        for j in range(n):
            for k in trees[i][j]:
                # 가을에는 나무가 번식
                if k % 5 == 0:
                    for l in range(8):
                        x = i + dx[l]
                        y = j + dy[l]
                        if 0 <= x < n and 0 <= y < n:
                            trees[x][y].appendleft(1)
            # 겨울에는 양분을 추가
            land[i][j] += add[i][j]


dx = [1, -1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, -1, 1, 1, -1, -1, 1]
n, m, k = map(int, input().split())
land = [[5] * n for _ in range(n)]
add = []
trees = [[deque() for _ in range(n)] for _ in range(n)]

# 매년 추가될 양분의 양 입력 받기
for i in range(n):
    add.append(list(map(int, input().split())))

# 나무 정보 입력 받기
for _ in range(m):
    i, j, age = map(int, input().split())
    trees[i - 1][j - 1].append(age)

# k년동안의 변화 지켜보기
for i in range(k):
    spring_and_summer()
    fall_and_winter()

# 살아남은 나무 개수 계산하기
cnt = 0
for i in range(n):
    for j in range(n):
        cnt += len(trees[i][j])

print(cnt)
