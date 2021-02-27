# dist가 최대 8이기 때문에 brute force를 통해 탐색이 가능하다.


from itertools import permutations


def solution(n, weak, dist):
    weakLen = len(weak)
    for i in range(weakLen):
        weak.append(weak[i] + n)

    # print(weak)
    answer = len(dist) + 1
    for i in range(weakLen):
        start = [weak[j] for j in range(i, i + weakLen)]
        candidates = permutations(dist, len(dist))
        for candidate in candidates:
            idx, count = 0, 1
            check = start[0] + candidate[idx]

            for j in range(weakLen):
                if start[j] > check:
                    count += 1
                    if count > len(candidate):
                        break
                    idx += 1
                    check = candidate[idx] + start[j]
            answer = min(answer, count)
    if answer > len(dist):
        return -1

    return answer


print(solution(12, [1, 5, 6, 10], [1, 2, 3, 4]))
