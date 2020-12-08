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


v, e = map(int, sys.stdin.readline().split())
arr = []
parent = [i for i in range(v + 1)]

for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    arr.append([a, b, c])

arr.sort(key=lambda x: x[2])

edgeCount = 0
ans = 0

# 크루스칼 알고리즘
for e in arr:
    a, b, weight = e
    if find(a) != find(b):
        union(a, b)
        ans += weight
        edgeCount += 1
    if edgeCount == v - 1:
        break

print(ans)
