def solution(m, n, board):
    answer = 0
    # 두개의 배열을 만들어서
    for i in range(m):
        board[i] = list(map(str, board[i]))

    while True:

        # 보드의 블록 부서질곳찾기
        arr = [[0] * n for _ in range(m)]
        flag = True
        for i in range(m - 1):
            for j in range(n - 1):
                if board[i][j] != -1 and len({board[i][j], board[i][j + 1], board[i + 1][j], board[i + 1][j + 1]}) == 1:
                    arr[i][j], arr[i][j + 1], arr[i + 1][j], arr[i + 1][j + 1] = 1, 1, 1, 1
                    flag = False

        # 부서질 곳이 없으면 게임끝
        if flag:
            break

        # 부서질 곳을 답에 추가
        for i in range(m):
            for j in range(n):
                if arr[i][j] == 1:
                    answer += 1

        # 부서질곳을 빼주고 높이 당겨준다. 세로로 검사
        for i in range(n):
            for j in range(m):
                if arr[j][i] == 1:
                    for k in range(j, 0, -1):
                        board[k][i] = board[k - 1][i]
                    board[0][i] = -1
        # for i in range(m):
        #     for j in range(n):
        #         print(board[i][j], end=" ")
        #     print()

    return answer


print(solution(4, 5, ["CCBDE", "AAADE", "AAABF", "CCBBF"]))
