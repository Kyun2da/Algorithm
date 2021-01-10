from itertools import permutations


def isPrime(num):
    if num == 0 or num == 1:
        return False

    for i in range(2, num // 2 + 1):
        if (num / i) == (num // i):
            return False
    return True


def solution(numbers):
    answer = 0
    arr = list(numbers)
    newSet = set()
    for i in range(1, len(arr) + 1):
        permute = [*permutations(arr, i)]
        # print(permute)
        for x in list(permute):
            # print(x)
            newSet.add(int(''.join(map(str, x))))

    # print(newSet)
    for item in newSet:
        if isPrime(item):
            answer += 1

    return answer
