def solution(n, words):
    arr = []
    for i, word in enumerate(words):
        if word in arr:
            return [i % n + 1, i // n + 1]
        elif i != 0 and words[i - 1][-1] != word[0]:
            return [i % n + 1, i // n + 1]
        else:
            arr.append(word)

    return [0, 0]


print(solution(3, ['tank', 'kick', 'know', 'wheel', 'land', 'dream', 'mother', 'robot', 'tank']))
