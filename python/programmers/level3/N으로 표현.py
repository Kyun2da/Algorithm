def solution(N, number):
    dp = [0, {N}]

    if N == 1 or N == number: return N % number + 1

    for i in range(2, 9):
        setA = {int(str(N) * i)}
        for j in range(1, i // 2 + 1):
            for x in dp[j]:
                for y in dp[i - j]:
                    setA.add(x + y)
                    setA.add(x - y)
                    setA.add(y - x)
                    setA.add(x * y)
                    if x != 0:
                        setA.add(y // x)
                    if y != 0:
                        setA.add(x // y)
        if number in setA:
            return i
        dp.append(setA)
    return -1


print(solution(5, 12))
