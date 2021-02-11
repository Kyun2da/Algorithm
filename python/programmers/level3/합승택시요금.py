# 방법은 총 세가지 가 존재 이중 가장 비용이 작은 값을 선택한다.
# 1. 2명이 같은 택시에 탑승해서 가다가 특정 지점에서 헤어져서 각자 목적지까지 이동하는 방식
# 2. 2명이 같은 택시에 탑승하고 한명의 목적지까지 먼저 도착한다음 또다른 사람의 목적지까지 가는 방식
# 3. 서로 따로 출발해서 각자 목적지까지 가는 방식

from heapq import heappush, heappop

graph = []


def dijk(s, e):
    global graph
    q = [[0, s]]
    n = len(graph)
    distance = [1e9] * (n + 1)
    distance[s] = 0
    while q:  # 큐가 비어있지 않다면
        # 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        dist, now = heappop(q)
        # 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if distance[now] < dist:
            continue
        # 현재 노드와 연결된 다른 인접한 노드들을 확인
        for i in graph[now]:
            cost = dist + i[1]
            # 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heappush(q, (cost, i[0]))
    return distance[e]


def solution(n, s, a, b, fares):
    global graph
    graph = [[] for _ in range(n + 1)]

    for fare in fares:
        start, end, money = fare
        graph[start].append([end, money])
        graph[end].append([start, money])

    cost = dijk(s, a) + dijk(s, b)

    for i in range(1, n + 1):
        if s != i:
            cost = min(cost, dijk(s, i) + dijk(i, a) + dijk(i, b))

    return cost


print(solution(6, 4, 6, 2,
               [[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22],
                [1, 6, 25]]))
