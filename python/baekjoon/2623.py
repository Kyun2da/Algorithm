import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
indegree = [0] * (n + 1) # 진입 차수
arr = [[] for _ in range(n + 1)]

for i in range(m):
    tmp = list(map(int, input().split()))
    for j in range(1, tmp[0]):
        arr[tmp[j]].append(tmp[j + 1])
        indegree[tmp[j + 1]] += 1

result = []
queue = deque()

for i in range(1, n+1):
    if indegree[i] == 0:
        queue.append(i)

while len(queue):
    tmp = queue.popleft()
    result.append(tmp)

    for x in arr[tmp]:
        indegree[x] -= 1
        if indegree[x] == 0:
            queue.append(x)

if len(result) == n:
    for x in result:
        print(x)
else:
    print(0)

