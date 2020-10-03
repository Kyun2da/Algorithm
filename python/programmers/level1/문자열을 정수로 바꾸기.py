def solution(s):
    if s[0] == '-1':
        return -1 * int(s[1:])
    return int(s)
