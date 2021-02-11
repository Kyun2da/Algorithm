def isPalindrome(s):
    length = len(s)
    if length % 2 == 0:
        if s[:length // 2] == s[-1: length // 2 - 1:-1]:
            return True
    else:
        if s[:length // 2] == s[-1:length // 2:-1]:
            return True
    return False


def solution(s):
    answer = 1
    length = len(s)
    for i in range(length - 1):
        for j in range(i + 1, length):
            if isPalindrome(s[i:j + 1]):
                answer = max(answer, j - i + 1)

    return answer


print(solution("abcdcba"))
