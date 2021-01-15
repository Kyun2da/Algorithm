answer = []


def divideConquer(x, y, n, arr):
    global answer
    check = arr[x][y]
    for i in range(x, x + n):
        for j in range(y, y + n):
            if check != arr[i][j]:
                divideConquer(x, y, n // 2, arr)
                divideConquer(x, y + n // 2, n // 2, arr)
                divideConquer(x + n // 2, y, n // 2, arr)
                divideConquer(x + n // 2, y + n // 2, n // 2, arr)
                return
    answer.append(check)


def solution(arr):
    global answer

    divideConquer(0, 0, len(arr), arr)
    return [answer.count(0), answer.count(1)]


print(solution([[1, 1, 0, 0], [1, 0, 0, 0], [1, 0, 0, 1], [1, 1, 1, 1]]))
answer = []
print(solution([[1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 1, 1, 1, 1], [0, 1, 0, 0, 1, 1, 1, 1],
                [0, 0, 0, 0, 0, 0, 1, 1], [0, 0, 0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 1, 0, 0, 1],
                [0, 0, 0, 0, 1, 1, 1, 1]]))
