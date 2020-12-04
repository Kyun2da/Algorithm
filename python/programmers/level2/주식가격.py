def solution(prices):
    length = len(prices)
    answer = [0] * length
    stack = []
    arr = []
    for x, i in enumerate(prices):
        arr.append([x, i])

    i = 0
    while i < length:
        x = arr[i]
        if len(stack) == 0:
            stack.append(x)
            i += 1
        else:
            # 스택의 맨 위 원소가 비교하고자 하는 원소보다 높을 때
            if stack[-1][1] > x[1]:
                idx = stack[-1][0]
                answer[idx] = x[0] - idx
                stack.pop()
            else:
                stack.append(x)
                i += 1
        # print(stack)

    while len(stack) != 0:
        x = stack[-1]
        answer[x[0]] = length - x[0] -1
        stack.pop()

    return answer


print(solution([1, 2, 3, 2, 3]))
