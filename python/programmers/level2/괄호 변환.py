def isCorrect(s):
    num = 0
    for x in s:
        if x == '(':
            num += 1
        else:
            num -= 1
        if num < 0:
            return False
    if num == 0:
        return True
    else:
        return False


def logic(p):
    # 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환
    if len(p) == 0:
        return ""
    elif isCorrect(p):
        return p
    # 2. w를 두 균형잡힌 괄호 문자열 u,v 로 분리한다.
    num = 0
    idx = 0
    while True:
        if p[idx] == '(':
            num += 1
        else:
            num += -1
        if num == 0:
            break
        idx += 1
    u = p[0:idx + 1]
    v = p[idx + 1:]
    # print(u, "그리고", v)
    if isCorrect(u):
        u += logic(v)
        return u
    else:
        tmp = "("
        tmp += logic(v) + ")"
        tmp += ''.join(list(map(lambda x: '(' if x == ')' else ')', u[1:-1])))
        return tmp


def solution(p):
    answer = logic(p)
    return answer


print(solution("()))((()"))
