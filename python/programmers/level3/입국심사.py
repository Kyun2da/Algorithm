def solution(n, times):
    times.sort()
    answer = 1e9
    left = 1
    right = times[-1] * n

    while left <= right:
        mid = (left + right) // 2
        count = 0
        for time in times:
            count += (mid // time)
            if count >= n:
                answer = min(answer, mid)

        if count >= n:
            right = mid - 1
        else:
            left = mid + 1

    return answer


print(solution(6, [7, 10]))
