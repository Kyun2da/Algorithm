from collections import deque


def rotateLeft(num, move):
    if num < 1 or gear[num + 1][6] == gear[num][2]:
        return
    rotateLeft(num - 1, -move)
    gear[num].rotate(move)


def rotateRight(num, move):
    if num > 4 or gear[num - 1][2] == gear[num][6]:
        return
    rotateRight(num + 1, -move)
    gear[num].rotate(move)


gear = [[]]  # 0인덱스에 빈 배열 놓기

for _ in range(4):
    gear.append(deque(map(int, input())))

n = int(input())

for _ in range(n):
    idx, moves = map(int, input().split())
    # 회전하기
    rotateLeft(idx - 1, -moves)
    rotateRight(idx + 1, -moves)
    gear[idx].rotate(moves)

ans = 0
for i in range(4):
    ans += (2 ** i) * gear[i + 1][0]

print(ans)
