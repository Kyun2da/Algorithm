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


# 노드와 간선의 정보 받기
v, e = map(int, sys.stdin.readline().split())
# 간선의 정보가 들어갈 arr 배열
arr = []
# 노드 각각의 루트 노드 배열 정보가 들어갈 parent 배열
parent = [i for i in range(v + 1)]

# 간선의 정보 받음
for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    arr.append([a, b, c])

# 간선의 가중치를 작은 순서로 정렬
arr.sort(key=lambda x: x[2])

# 간선 개수와 가중치 합을 구할 변수
edgeCount = 0
ans = 0

# 크루스칼 알고리즘 (간선을 돌며 사이클을 생성하지 않는 선에서 노드들을 잇는다.)
for e in arr:
    a, b, weight = e
    if find(a) != find(b):
        union(a, b)
        ans += weight
        edgeCount += 1
    # 간선의 개수가 노드개수 - 1 이면 종료
    if edgeCount == v - 2:
        break

print(ans)