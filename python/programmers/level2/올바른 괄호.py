def solution(s):
    num = 0
    for i in s:
        if i == "(":
            num += 1
        else:
            num -= 1
        if num < 0:
            return False

    if num != 0:
        return False
    return True


print(solution("()()"))
