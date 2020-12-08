# 프림 알고리즘

### 1. 프림 알고리즘 이란?

프림 알고리즘은 하나의 시작점을 잡고 시작점과 연결된 정점들에 대해 가장 가중치가 작은 간선부터 연결해주면서 최소 스패닝 트리를 만들어 나가는 알고리즘을 의미합니다. 보통 자료구조는 우선순위 큐를 이용하여 가중치가 가장 작은 간선을 먼저 뺄 수 있도록 합니다.

단, 사이클이 생긴다면 해당 간선은 제외하고 진행하도록합니다.

크루스칼 알고리즘과 마찬가지로 정점의 수 - 1== 간선의 수가 될 때까지 알고리즘을 진행합니다.

진행 방식은 다음과 같습니다.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f7/Prim%27s_algorithm.svg/120px-Prim%27s_algorithm.svg.png)

1. 먼저 임의로 A 노드를 선택하고 A노드와 연결된 간선을 우선순위 큐에 넣고 그중 가장 작은 간선인 A-D 간선을 선택합니다. 
2. D노드가 연결되었으므로 D노드와 연결된 간선을 우선순위 큐에 넣습니다.
3. 그 다음으로 가중치가 가장 작은 간선 B-D 를 넣습니다 (A-B를 넣어도 상관 없음)
4. B에 연결된 간선을 모두 넣습니다.
5. 여기서 그다음 작은 간선이 A-B이지만 사이클이 생성되므로 이 간선은 제외하고 C-D 간선을 넣습니다.
6. 총 간선수가 노드의 개수보다 1이 작으므로 알고리즘을 종료합니다.



이제 [백준 1197 최소 스패닝 트리](https://www.acmicpc.net/problem/1197) 를 통하여 코드를 살펴보도록 하겠습니다.

### 2. 코드

```python
import sys
import heapq

# 프림 알고리즘
def prim(x):
    q = []
    vis = [False] * (v + 1)
    vis[x] = True
    ans = 0
    edgeCount = 0

    # 우선순위 큐에 해당 정점에 이어져있는 간선 정보 삽입
    for item in adj[x]:
        heapq.heappush(q, item)

    # 우선순위 큐가 비거나 MST를 만족할 때까지 계속 간선을 추가해준다.
    while q:
        w, v1 = heapq.heappop(q)
        if not vis[v1]:
            vis[v1] = True
            edgeCount += 1
            ans += w
            for item in adj[v1]:
                heapq.heappush(q, item)
        if edgeCount == v - 1:
            return ans
    return 0


# 노드와 간선 개수를 받는다.
v, e = map(int, sys.stdin.readline().split())
# 간선정보가 들어갈 간선 배열 선언
adj = [[] for _ in range(v + 1)]

# 간선정보를 간선 배열에 넣는다.
for _ in range(e):
    a, b, weight = map(int, sys.stdin.readline().split())
    adj[a].append([weight, b])
    adj[b].append([weight, a])

print(prim(1))
```

### 3. 코드 설명

1. 프림알고리즘을 위해선 우선순위 큐가 보통 많이 쓰입니다. 그러므로 해당 라이브러리인 heapq 를 임포트 하도록 합니다.
2. 임의로 선택한 정점과 관련된 간선을 모두 우선순위 큐에 넣습니다. 그리고 해당 노드는 방문 처리를 해주도록 합니다.
3. 방문한 노드가 아니라면 해당 간선을 더해주고 그 노드 또한 방문처리 해줍니다. 그리고 그 노드와 관련된 간선을 모두 우선순위 큐에 넣습니다.
4. 우선순위 큐가 비거나 간선의 개수 == 노드의 개수 -1 일 때 까지 3번을 반복합니다.



### 4. 시간 복잡도

프림 알고리즘은 모든 정점을 우선순위 큐로 확인하니 logV 이고 그 정점들에 대하여 간선을 확인해 E 의 시간복잡도가 곱해집니다.

따라서 시간복잡도는 **O(ElogV)**가 됩니다.

