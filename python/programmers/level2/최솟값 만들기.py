def solution(A, B):
    answer = 0
    A.sort()
    B.sort(reverse=True)
    for x, y in zip(A, B):
        answer += x * y

    return answer


print(solution([1, 4, 2], [5, 4, 4]))
