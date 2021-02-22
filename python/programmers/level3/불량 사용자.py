from itertools import permutations


def check(candidate, banned_id):
    for x, y in zip(candidate, banned_id):
        if len(x) != len(y):
            return False
        for a, b in zip(x, y):
            if a != b and b != '*':
                return False
    return True


def solution(user_id, banned_id):
    answer = list()
    candidates = permutations(user_id, len(banned_id))
    for candidate in candidates:
        if check(candidate, banned_id):
            candidate = set(candidate)
            if candidate not in answer:
                answer.append(candidate)

    #print(answer)
    return len(answer)


print(solution(	["frodo", "fradi", "crodo", "abc123", "frodoc"], ["*rodo", "*rodo", "******"]))
