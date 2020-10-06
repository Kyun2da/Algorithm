def solution(x):
    k = x
    num = 0
    while k != 0:
        num += k % 10
        k //= 10
    if x % num == 0:
        return True
    return False
