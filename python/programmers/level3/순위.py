def solution(n, results):
    answer = 0

    wins = {}
    loses = {}

    for i in range(1, n + 1):
        wins[i] = set()
        loses[i] = set()

    for result in results:
        winner, loser = result
        wins[winner].add(loser)
        loses[loser].add(winner)

    for i in range(1, n + 1):
        # i를 이긴 사람들은 i에게 진사람들또한 이긴다.
        for winner in loses[i]:
            wins[winner].update(wins[i])
        # i에게 진 사람들은 i를 이긴사람들에게도 진다.
        for loser in wins[i]:
            loses[loser].update(loses[i])

    for i in range(1, n + 1):
        if len(wins[i]) + len(loses[i]) == n - 1:
            answer += 1
    return answer


print(solution(5, [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))
