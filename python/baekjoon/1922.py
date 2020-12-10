import sys


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


n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

edgeArr = []
parent = [i for i in range(n + 1)]
edgeCount = 0
ans = 0

for _ in range(m):
    a, b, weight = map(int, sys.stdin.readline().split())
    edgeArr.append([a, b, weight])

edgeArr.sort(key=lambda x: x[2])

for e in edgeArr:
    a, b, weight = e
    if find(a) != find(b):
        union(a, b)
        ans += weight
        edgeCount += 1
    if edgeCount == n - 1:
        break

print(ans)
