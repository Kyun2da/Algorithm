def solution(n):
    idx = 1
    num = 0
    arr = []
    answer = []
    for i in range(1, n + 1):
        arr.append([0] * i)
        num += i

    y = 0
    x = 0
    # print(arr)
    while idx <= num:
        # 아래로 쭉 간다.
        while y < n and arr[y][x] == 0:
            arr[y][x] = idx
            idx += 1
            y += 1
        # print(arr)
        y -= 1
        x += 1
        while x < n and arr[y][x] == 0:
            arr[y][x] = idx
            idx += 1
            x += 1
        # print(arr)
        y -= 1
        x -= 2
        while 0 <= x < n and 0 <= y < n and arr[y][x] == 0:
            arr[y][x] = idx
            idx += 1
            y -= 1
            x -= 1
        y += 2
        x += 1
        # print(y, x)
        # 오른쪽으으로 쭉 간다.
        # print(arr)
    for i in range(n):
        for j in range(i + 1):
            answer.append(arr[i][j])
    return answer


print(solution(6))
