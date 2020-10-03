def solution(s):
    arr = s.split(' ')
    idx = 0
    for x in arr:
        answer = ''
        for i in range(len(x)):
            if i % 2 == 0:
                answer += x[i].upper()
            else:
                answer += x[i].lower()
        arr[idx] = answer
        idx += 1

    return ' '.join(map(str, arr))


print(solution("try hello world"))
