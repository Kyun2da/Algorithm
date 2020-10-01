def isnumber(s):
    for i in range(len(s)):
        if s[i] < '0' or s[i] > '9':
            return False
    return True


def solution(s):
    if (len(s) == 4 or len(s) == 6) and isnumber(s):
        return True
    return False
