from collections import deque


def solution(n, edge):
    answer = 0
    graph = [[] for _ in range(n + 1)]

    for x in edge:
        graph[x[0]].append(x[1])
        graph[x[1]].append(x[0])

    vis = [False] * (n + 1)
    q = deque([1])
    vis[1] = True
    while q:
        tmp = 0
        for i in range(len(q)):
            x = q.popleft()
            for j in range(len(graph[x])):
                node = graph[x][j]
                if not vis[node]:
                    tmp += 1
                    q.append(node)
                    vis[node] = True
        if tmp != 0:
            answer = tmp

    return answer


print(solution(6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))
