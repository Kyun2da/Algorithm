ans = 0
arr = list(str(input()))
stack = 0

i = 0
while i < len(arr):
    if arr[i] == "(":
        # 레이저
        if arr[i + 1] == ")":
            ans += stack
            i += 1
        # 레이저가 아님
        else:
            stack += 1
            ans += 1
    else:
        stack -= 1
    i += 1

print(ans)
