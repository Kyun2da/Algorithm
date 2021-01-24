from itertools import combinations


def isPrime(num):
    if num == 0 or num == 1:
        return False

    for i in range(2, num // 2 + 1):
        if (num / i) == (num // i):
            return False
    return True


def solution(nums):
    a = combinations(nums, 3)
    answer = 0
    for i in a:
        if isPrime(sum(i)):
            answer += 1

    return answer


print(solution([1, 2, 3, 4]))
