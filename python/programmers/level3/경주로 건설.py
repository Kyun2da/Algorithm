from collections import deque


# 방향이 바뀌면 코너 500원 추가
# 그외의 전진은 100원씩 추가
# 큐의 들어갈 값은 [y좌표,x좌표, 방향, 금액] 으로 생각하자
def solution(board):
    length = len(board)
    lineM = 100
    cornerM = 500
    board[0][0] = 1  # 처음시작하는 곳을 벽으로 만들어 다음에 못오게 만들기
    q = deque([[0, 0, -1, 0]])
    dy = [0, 0, -1, 1]
    dx = [-1, 1, 0, 0]

    while q:
        for _ in range(len(q)):
            y, x, pos, money = q.popleft()
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                # ny, nx 가 갈수있는 곳일때
                if 0 <= ny < length and 0 <= nx < length and board[ny][nx] != 1:
                    # 처음 시작할때는 방향 고려 x
                    if pos == -1:
                        board[ny][nx] = lineM
                        q.append([ny, nx, i, lineM])
                    # 그 외에는 방향을 고려하고 이미 간 곳인지 체크 하고 더 싸게 갈수있는지 체크한다.
                    else:
                        fare = lineM if pos == i else lineM + cornerM
                        if board[ny][nx] == 0:
                            board[ny][nx] = money + fare
                            q.append([ny, nx, i, money + fare])
                        elif board[ny][nx] >= money + fare:
                            board[ny][nx] = money + fare
                            q.append([ny, nx, i, money + fare])
                        else:
                            continue

    # for i in range(length):
    #     for j in range(length):
    #         print(board[i][j], end=" ")
    #     print()

    return board[-1][-1]


# print(solution([[0, 0, 0], [0, 0, 0], [0, 0, 0]]))
# print(solution([[0, 0, 0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1, 0, 0], [0, 0, 0, 0, 1, 0, 0, 0],
#                 [0, 0, 0, 1, 0, 0, 0, 1], [0, 0, 1, 0, 0, 0, 1, 0], [0, 1, 0, 0, 0, 1, 0, 0],
#                 [1, 0, 0, 0, 0, 0, 0, 0]]))
print(solution([[0, 0, 1, 0], [0, 0, 0, 0], [0, 1, 0, 1], [1, 0, 0, 0]]))
