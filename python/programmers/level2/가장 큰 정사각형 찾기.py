def solution(board):
    answer = 0
    for i in range(1, len(board)):
        for j in range(1, len(board[i])):
            if board[i][j] == 1:
                board[i][j] = min(board[i - 1][j - 1], board[i - 1][j], board[i][j - 1]) + 1
                if answer < board[i][j]:
                    answer = board[i][j]
    return answer * answer


print(solution([[0, 0, 1, 1], [1, 1, 1, 1]]))
