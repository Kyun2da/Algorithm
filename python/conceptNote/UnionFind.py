# 유니온 파인드 알고리즘: 그래프 노드간의 연결관계를 파악할 때 유용한 알고리즘
# 핵심 연산으로 union(서로 다른 두 트리)과 Find가 존재한다.

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


parent = [0, 1, 2, 3, 4, 5, 6]

if find(3) == find(5):
    print("같은 집합입니다.")
else:
    print("다른 집합입니다.")

union(3, 5)

if find(3) == find(5):
    print("같은 집합입니다.")
else:
    print("다른 집합입니다.")

# 출력내용
# 다른 집합입니다.
# 같은 집합입니다.
