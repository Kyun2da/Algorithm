def gcd(a, b):
    while b > 0:
        tmp = b
        b = a % b
        a = tmp
    return a


def solution(w, h):
    answer = w * h
    answer -= w + h - gcd(w, h)
    return answer


print(solution(8, 12))
