def solution(s):
    us = s.upper()
    if us.count('P') != us.count('Y'):
        return False
    return True


print(solution('pPoooyY'))
