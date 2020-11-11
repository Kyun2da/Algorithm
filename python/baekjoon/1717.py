# union find 알고리즘

import sys

input = sys.stdin.readline


def get_parent(x):
    if parent[x] == x:
        return x
    p = get_parent(parent[x])
    parent[x] = p
    return p


def union(x, y):
    x = get_parent(x)
    y = get_parent(y)

    if x != y:
        parent[y] = x


def find_parent(x):
    if parent[x] == x:
        return x
    return find_parent(parent[x])


n, m = map(int, input().split())

parent = {}

for i in range(n + 1):
    parent[i] = i

for _ in range(m):
    com, a, b = map(int, input().split())
    if com == 0:
        union(a, b)
    else:
        if find_parent(a) == find_parent(b):
            print('YES')
        else:
            print('NO')
