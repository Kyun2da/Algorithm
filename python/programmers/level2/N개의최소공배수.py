from math import gcd


def solution(arr):
    answer = 1
    for x in arr:
        answer = answer * x // gcd(answer,x)
    return answer


print(solution([2, 6, 8, 14]))
