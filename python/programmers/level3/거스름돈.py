def solution(n, money):
    arr = [0] * (n + 1)
    arr[0] = 1
    for k in money:
        for i in range(1, n + 1):
            if i - k >= 0:
                arr[i] += arr[i - k]
    return arr[n]


print(solution(5, [1, 2, 5]))
