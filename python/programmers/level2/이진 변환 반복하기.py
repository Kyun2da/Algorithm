def solution(s):
    answer = [0, 0]
    while s != "1":
        tmp = ""
        for x in s:
            if x == "1":
                tmp += "1"
            else:
                answer[1] += 1
        s = format(len(tmp), 'b')
        answer[0] += 1
    return answer


print(solution("110010101001"))
