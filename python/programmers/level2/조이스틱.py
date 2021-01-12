def solution(name):
    arr = ['A'] * len(name)
    i = 0
    ans = 0
    while True:
        # 현재 위치의 알파벳을 name 알파벳과 동일하게 바꾼다.
        ans += min(ord(name[i]) - ord("A"), ord("Z") - ord(name[i]) + 1)
        arr[i] = name[i]
        # 만약 알파벳 하나를 바꾼 후 name 과 일치한다면 종료
        if ''.join(map(str, arr)) == name:
            break
        # 바꾸는 곳의 가장 가까운 다음 알파벳으로 간다.
        left, right = 1, 1
        while name[i - left] == arr[i - left]:
            left += 1
        while name[i + right] == arr[i + right]:
            right += 1
        if left < right:
            i = i - left
            ans += left
        else:
            i = i + right
            ans += right
        # print(''.join(map(str, arr)))
        # print(ans)
    return ans


print(solution("JEROEN"))
