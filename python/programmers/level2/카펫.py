def solution(brown, yellow):
    if yellow == 1:
        return [3, 3]
    for i in range(1, yellow):
        if yellow / i == yellow // i and i * 2 + yellow // i * 2 + 4 == brown:
            return [yellow // i + 2, i + 2]


print(solution(24, 24))
