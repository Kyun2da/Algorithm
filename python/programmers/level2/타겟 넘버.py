answer = 0


def dfs(idx, total, target, numbers):
    global answer
    if idx == len(numbers):
        if total == target:
            answer += 1
            return
        return
    dfs(idx + 1, total + numbers[idx], target, numbers)
    dfs(idx + 1, total - numbers[idx], target, numbers)


def solution(numbers, target):
    global answer
    answer = 0
    dfs(0, 0, target, numbers)
    return answer


print(solution([1, 1, 1, 1, 1], 3))
