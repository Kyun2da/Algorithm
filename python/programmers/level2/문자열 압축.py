def compression(s, i):
    newS = ""
    idx = 0
    # print("%d개씩 압축" % i)
    # 문자열을 순회하며 압축한다
    while idx < len(s):
        tmp = s[idx:idx + i]
        # print(tmp)
        # 같은 문자열이 나올때까지 압축
        num = 1
        while True:
            tmp2 = s[idx + i:idx + i * 2]
            if tmp == tmp2:
                num += 1
                idx += i
            else:
                break
        # 같은 문자열이 나왔으면 새로운 문자에 같은 문자나온만큼 더해줌
        if num > 1:
            newS += str(num) + tmp
        else:
            newS += tmp
        idx += i
        # print("newS는 %s" % newS)
    # print(len(newS))
    return len(newS)


def solution(s):
    answer = len(s)
    # 1개부터 len(s)개까지 압축을해서 제일 작은 문자열 길이를 찾는다.
    for i in range(1, len(s) + 1):
        length = compression(s, i)
        if answer > length:
            answer = length

    return answer


print(solution("xababcdcdababcdcd"))
