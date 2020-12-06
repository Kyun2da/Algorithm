# 위상 정렬
# 1. 간선리스트 그래프와 큐를 이용
# 2. 방향 그래프에서만 위상정렬을 쓸 수 있다.
# 3. 진입 차수가 0인 노드를 시작할 때 큐에 넣는다.
# 4. 큐를 pop하며 pop한 노드와 연결된 것의 진입 차수를 -1 해주고 진입차수가 0이 되면 그 노드를 또 push
# 5. 3,4를 큐가 빌때까지 계속 진행

from collections import deque

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
inDeg = [0] * (n + 1)
q = deque()
result = []

for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    inDeg[y] += 1

for i in range(1, n + 1):
    if inDeg[i] == 0:
        q.append(i)

while q:
    a = q.popleft()
    result.append(a)
    for x in graph[a]:
        inDeg[x] -= 1
        if inDeg[x] == 0:
            q.append(x)

print(*result)
