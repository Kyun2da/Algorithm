'''
        dfs로 돌리면서 하나하나 나아가서 답이 target이 되는 순간 number를 리턴하자
        차이가 한개인지를 리턴하는 함수 만들기
'''


def isDiffrentOne(curWord, nextWord):
    num = 0
    for x, y in zip(curWord, nextWord):
        if x != y:
            num += 1
            if num > 1:
                return False
    if num == 1:
        return True
    return False


def solution(begin, target, words):
    global answer
    answer = 51

    def dfs(curWord, num, vis):
        global answer
        if curWord == target:
            answer = min(answer, num)
            return

        for i in range(len(words)):
            if not vis[i] and isDiffrentOne(curWord, words[i]):
                vis[i] = True
                dfs(words[i], num + 1, vis)
                vis[i] = False

    dfs(begin, 0, [False] * len(words))
    return answer if answer != 51 else 0


print(solution("hit", "cog", ['hot', 'dot', 'dog', 'lot', 'log', 'cog']))
print(solution('hit', 'cog', ['hot', 'dot', 'dog', 'lot', 'log']))
