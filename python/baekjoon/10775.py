import sys

input = sys.stdin.readline


def find(target):
    if target == parent[target]:
        return target

    # 경로 압축 최적화
    parent[target] = find(parent[target])
    return parent[target]


def union(a, b):
    a = find(a)
    b = find(b)

    # 작은 루트 노드를 기준으로 합침
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


g = int(input())
p = int(input())
arr = list(int(input()) for _ in range(p))

parent = {i: i for i in range(g + 1)}
ans = 0

for x in arr:
    tmp = find(x)
    if tmp == 0:
        break
    union(tmp, tmp - 1)
    ans += 1

print(ans)
