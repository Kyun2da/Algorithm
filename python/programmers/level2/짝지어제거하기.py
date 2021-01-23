def solution(s):
    stack = []

    for i in range(len(s)):
        if len(stack) == 0 or stack[-1] != s[i]:
            stack.append(s[i])
        else:
            stack.pop()

    return 1 if not stack else 0


print(solution("baabaa"))
