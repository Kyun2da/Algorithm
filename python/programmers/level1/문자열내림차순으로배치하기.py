def solution(s):
    arr = list(s)
    arr.sort(reverse=True)
    answer = ''.join(map(str, arr))
    return answer


print(solution('Zbcdefg'))
