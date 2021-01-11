def solution(number, k):
    answer = number
    i = 0
    while i < len(number) - 1 and k > 0:
        if answer[i] < answer[i + 1]:
            answer = answer[:i] + answer[i + 1:]
            k -= 1
            if i != 0:
                i -= 1
        else:
            i += 1
    if k > 0:
        return answer[:-k]
    return answer


print(solution("4177252841", 4))
