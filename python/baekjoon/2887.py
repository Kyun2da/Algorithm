import sys

input = sys.stdin.readline


def find(target):
    if target == parent[target]:
        return target

    parent[target] = find(parent[target])
    return parent[target]


def union(a, b):
    a = find(a)
    b = find(b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b


n = int(input())
edges = []
planet = []
parent = [i for i in range(n + 1)]

for i in range(n):
    x, y, z = map(int, input().split())
    planet.append((x, y, z, i))

for i in range(3):
    planet.sort(key=lambda x: x[i])
    for j in range(1, n):
        edges.append((abs(planet[j - 1][i] - planet[j][i]), planet[j - 1][3], planet[j][3]))

edges.sort()
edgeCount = 0
ans = 0

for e in edges:
    weight, a, b = e
    if find(a) != find(b):
        union(a, b)
        ans += weight
        edgeCount += 1
    # 간선의 개수가 노드개수 - 1 이면 종료
    if edgeCount == n - 1:
        break

print(ans)
