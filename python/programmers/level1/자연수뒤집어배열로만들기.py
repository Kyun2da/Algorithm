def solution(n):
    answer = list(reversed(str(n)))
    for i in range(len(answer)):
        answer[i] = int(answer[i])
    return answer


print(solution(12345))