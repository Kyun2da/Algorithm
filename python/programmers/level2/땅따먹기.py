def solution(land):
    for i in range(1, len(land)):
        for j in range(len(land[i])):
            if j == 0:
                land[i][j] += max(land[i - 1][j + 1], land[i - 1][j + 2], land[i - 1][j + 3])
            elif j == 1:
                land[i][j] += max(land[i - 1][j - 1], land[i - 1][j + 1], land[i - 1][j + 2])
            elif j == 2:
                land[i][j] += max(land[i - 1][j - 2], land[i - 1][j - 1], land[i - 1][j + 1])
            elif j == 3:
                land[i][j] += max(land[i - 1][j - 3], land[i - 1][j - 2], land[i - 1][j - 1])

    return max(land[len(land) - 1])


print(solution([[1, 2, 3, 5], [5, 6, 7, 8], [4, 3, 2, 1]]))
