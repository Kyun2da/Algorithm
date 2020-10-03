def solution(s, n):
    answer = ""
    for x in s:
        if 'a' <= x <= 'z':
            answer += chr((ord(x) + n - 97) % 26 + 97)
        elif 'A' <= x <= 'Z':
            answer += chr((ord(x) + n - 65) % 26 + 65)
        else:
            answer += x
    return answer


print(solution('z', 1))
