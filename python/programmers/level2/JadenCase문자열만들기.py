def solution(s):
    arr = s.split(" ")
    for i in range(len(arr)):
        arr[i] = arr[i].capitalize()

    answer = " ".join(map(str, arr))

    return answer


print(solution("3people unFollowed me"))
