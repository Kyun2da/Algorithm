def solution(a, b):
    day = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']
    dayOfMonth = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    ans = 4
    for i in range(a - 1):
        ans += dayOfMonth[i]
    ans += b
    answer = day[ans % 7]

    return answer


print(solution(5, 24))
