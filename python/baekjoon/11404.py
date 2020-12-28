import sys

input = sys.stdin.readline

INF = int(1e9)

# 도시의 개수와 버스의 개수
n = int(input())
m = int(input())

graph = [[INF] * (n + 1) for _ in range(n + 1)]

# 각 간선에 대한 정보를 입력받아, 그 값으로 초기화
for _ in range(m):
    # A에서 B로 가는 비용은 C라고 설정
    a, b, c = map(int, input().split())
    # A에서 B로가는 노선이 여러개 있을 수 있으므로 가장 작은 하나만 고른다.
    if graph[a][b] > c:
        graph[a][b] = c

# 점화식에 따라 플로이드 워셜 알고리즘을 수행
for k in range(1, n + 1):
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            if a != b:
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

# 수행된 결과를 출력
for a in range(1, n + 1):
    for b in range(1, n + 1):
        if graph[a][b] == INF:
            print(0, end=" ")
        # 도달할 수 있는 경우 거리를 출력
        else:
            print(graph[a][b], end=" ")
    print()
