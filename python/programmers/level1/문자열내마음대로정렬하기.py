def solution(strings, n):
    strings.sort(key=lambda x: (x[n], x))
    answer = strings
    return answer


print(solution(['sun', 'bed', 'car'], 1))
