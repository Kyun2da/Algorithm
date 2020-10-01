def solution(arr, divisor):
    answer = []
    for x in arr:
        if x % divisor == 0:
            answer.append(x)
    answer.sort()
    if len(answer) == 0:
        answer.append(-1)
    return answer


print(solution([5, 9, 7, 10], 5))
