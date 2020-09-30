def solution(answers):
    onep = [1, 2, 3, 4, 5]
    twop = [2, 1, 2, 3, 2, 4, 2, 5]
    threep = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    ans = [0, 0, 0]
    answer = []
    for i in range(len(answers)):
        if answers[i] == onep[i % 5]:
            ans[0] += 1
        if answers[i] == twop[i % 8]:
            ans[1] += 1
        if answers[i] == threep[i % 10]:
            ans[2] += 1
    for i in range(len(ans)):
        if max(ans) == ans[i]:
            answer.append(i + 1)

    return answer


print(solution([1, 2, 3, 4, 5]))
