# 자연수 n개로 이루어진 집합 중 합이 s 이면서 곱이 가장 큰 집합을 리턴하라

def solution(n, s):
    answer = []

    if n > s:
        return [-1]

    k = s // n

    for _ in range(n):
        answer.append(k)
    idx = n - 1
    for _ in range(s % n):
        answer[idx] += 1
        idx -= 1
    return answer


print(solution(2, 9))
