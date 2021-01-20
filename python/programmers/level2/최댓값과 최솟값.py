def solution(s):
    arr = s.split(" ")
    arr.sort(key=lambda x: int(x))
    s = arr[0] + " " + arr[-1]
    return s


print(solution("4 3 2 1"))
