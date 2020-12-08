# 크루스칼 알고리즘

### 1.크루스칼 알고리즘 이란?

크루스칼 알고리즘은 유니온 파인드 알고리즘을 이용하여 **가장 적은 비용으로 모든 노드를 연결하기 위한 알고리즘** 입니다.

유니온 파인드 알고리즘에 대하여 궁금하다면 [유니온파인드](../conceptNote/unionFind.md) 를 참조해 주세요.

### 2. 크루스칼 알고리즘 원리

크루스칼 알고리즘은 간선을 가중치가 짧은 순서대로 그래프에 포함시키면 어떨까? 하는 생각에서 시작됩니다.

이러한 원리로 크루스칼 알고리즘은 짧은 순서를 따라 노드를 이어갑니다.

단, 주의할 점은 **사이클이 생기면 안된다는 점** 입니다. 여기서 사이클을 검사할 때는 바로 **Union-Find** 알고리즘을 사용합니다.

그렇게 사이클을 만들지 않으며 최소 가중치 순서대로 간선을 이어가며, 간선의 개수 == 정점의 개수-1일 때 해당 알고리즘을 끝냅니다. 그 이유는 간선의 개수가 정점의 개수보다 하나 작을 때 모든 정점을 최소의 간선 수로 이을 수 있기 때문입니다.

그림으로 순서를 보면 다음과 같습니다. ([위키피디아 크루스칼 알고리즘- 출처](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm))

1. 먼저 가중치가 가장 작은 A-D 간선을 잇습니다.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/b/b4/Kruskal_Algorithm_1.svg/200px-Kruskal_Algorithm_1.svg.png)

2. 마찬가지로, C-E 간선을 또 이어 줍니다.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Kruskal_Algorithm_2.svg/200px-Kruskal_Algorithm_2.svg.png)

3. D-F 간선을 잇습니다.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/5/59/Kruskal_Algorithm_3.svg/200px-Kruskal_Algorithm_3.svg.png)

4.  그 다음 작은 간선인 A,B를 잇습니다.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2e/Kruskal_Algorithm_4.svg/200px-Kruskal_Algorithm_4.svg.png)

5. 그 후 B와 E를 잇습니다.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f4/Kruskal_Algorithm_5.svg/200px-Kruskal_Algorithm_5.svg.png)

6. B-C, E-F, B,D 간선은 그다음으로 작지만 사이클이 발생하므로 잇지않습니다. E-G간선을 잇고 간선의 개수(6) == 노드의 개수(7) - 1이므로 알고리즘을 종료합니다.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/8/87/Kruskal_Algorithm_6.svg/200px-Kruskal_Algorithm_6.svg.png)

그럼 [백준 1197 최소스패닝 트리](https://www.acmicpc.net/problem/1197) 를 예로 코드 설명을 시작해 보겠습니다.

### 3. 코드

```python
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
    if edgeCount == v - 1:
        break

print(ans)

```

### 4. 코드 설명

1. 먼저 노드의 개수와 간선의 개수 인풋을 받습니다.
2. 간선의 정보를 받습니다.
3. 크루스칼 알고리즘을 수행하기 위해 가중치가 작은 순으로 간선을 정렬합니다.
4. 정렬한 간선을 순회하며 사이클을 돌지 않는 선에서(검사는 Find를 이용) 노드를 합치며(Union 이용) 트리를 완성합니다.
5. 간선의 개수 == 노드개수 -1 이면 알고리즘을 종료하고 가중치의 합을 출력합니다. 

### 5. 시간 복잡도

크루스칼 알고리즘의 시간 복잡도는 간선을 정렬하는 시간에 좌우 됩니다.
$$
elog_{2}e
$$
따라서 위와 같은 시간복잡도를 가집니다.