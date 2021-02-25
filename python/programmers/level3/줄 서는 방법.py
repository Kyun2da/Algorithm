from math import factorial


def solution(n, k):
    answer = []
    order = [i for i in range(1, n + 1)]
    while n != 0:
        fact = factorial(n - 1)
        answer.append(order.pop((k - 1) // fact))
        n = n - 1
        k = k % fact
        print(answer, order)
    return answer


print(solution(3, 5))
