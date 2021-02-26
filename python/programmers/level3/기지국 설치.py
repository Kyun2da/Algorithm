import math


def solution(n, stations, w):
    answer = 0
    need5GApart = []
    start = 1
    for station in stations:
        need5GApart.append(station - w - start)
        start = station + w + 1
    if start <= n:
        need5GApart.append(n - start + 1)
    # print(need5GApart)
    for apart in need5GApart:
        answer += math.ceil(apart / (w * 2 + 1))
    return answer


print(solution(11, [4, 11], 1))
print(solution(16, [9], 2))
