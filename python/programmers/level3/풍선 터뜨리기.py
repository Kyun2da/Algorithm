def solution(a):
    answer = 0
    length = len(a)
    dp1 = [0] * length
    dp2 = [0] * length
    dp1[0] = a[0]
    dp2[-1] = a[-1]
    for i in range(1, len(a)):
        dp1[i] = min(dp1[i - 1], a[i])
    for i in range(len(a) - 2, -1, -1):
        dp2[i] = min(dp2[i + 1], a[i])
    for i in range(length):
        if dp1[i] == a[i] or dp2[i] == a[i]:
            answer += 1
    return answer