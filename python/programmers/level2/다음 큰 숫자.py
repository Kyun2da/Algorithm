def solution(n):
    lenOne = list(format(n, 'b')).count('1')
    for i in range(n + 1, 1000001):
        if list(format(i, 'b')).count('1') == lenOne:
            return i


print(solution(78))
