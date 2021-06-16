import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
s_node = None
d_node = int(input())
graph = [[] for _ in range(n)]

for i, x in enumerate(arr):
    # 삭제할 노드는 연결시키지 않는다.
    if i == d_node or x == d_node or x == -1:
        if x == -1:
            s_node = i
        continue
    graph[x].append(i)


def count_leaf_node(v):
    q = deque()
    q.append(v)
    count = 0
    while q:
        x = q.popleft()
        if len(graph[x]) == 0:
            count += 1
            continue
        for j in graph[x]:
            q.append(j)
    return count


if d_node == s_node:
    print(0)
else:
    print(count_leaf_node(s_node))
