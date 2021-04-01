import sys
from collections import deque

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())  # n : 건물의 개수, k : 건물간의 건설 순서 규칙의 총 개수
    d = [0] + list(map(int, input().split()))
    graph = [[] for _ in range(n + 1)]
    inDegree = [0 for _ in range(n + 1)]
    dp = [0 for _ in range(n + 1)]
    for _ in range(k):
        x, y = map(int, input().split())
        graph[x].append(y)
        inDegree[y] += 1

    w = int(input())

    q = deque()
    for i in range(1, n + 1):
        if inDegree[i] == 0:
            q.append(i)
            dp[i] = d[i]

    while q:
        node = q.popleft()
        for i in graph[node]:
            inDegree[i] -= 1
            dp[i] = max(dp[node]+d[i], dp[i])
            if inDegree[i] == 0:
                q.append(i)

    print(dp[w])
