def solution(n, computers):
    def dfs(num):
        for i in range(n):
            if not vis[i] and computers[num][i] == 1:
                vis[i] = True
                dfs(i)

    answer = 0
    vis = [False] * n
    for i in range(n):
        if not vis[i]:
            vis[i] = True
            answer += 1
            dfs(i)
    return answer


print(solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]))
