def solution(board, moves):
    arr = []
    answer = 0
    for move in moves:
        item = 0
        for i in range(len(board)):
            if board[i][move - 1] != 0:
                item = board[i][move - 1]
                board[i][move - 1] = 0
                break
        if item == 0:
            continue
        if len(arr) == 0 or arr[-1] != item:
            arr.append(item)
        else:
            arr.pop()
            answer += 2
    return answer


print(solution([[0, 0, 0, 0, 0], [0, 0, 1, 0, 3], [0, 2, 5, 0, 1], [4, 2, 4, 4, 2], [3, 5, 1, 3, 1]],
               [1, 5, 3, 5, 1, 2, 1, 4]))
