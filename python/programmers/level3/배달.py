import heapq


def solution(N, road, K):
    INF = 1e9
    answer = 0
    graph = [[] for i in range(N + 1)]
    # 최단 거리 테이블을 모두 무한으로 초기화
    distance = [INF] * (N + 1)

    for r in road:
        a, b, c = r
        graph[a].append((b, c))
        graph[b].append((a, c))

    q = []
    # 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    heapq.heappush(q, (0, 1))
    distance[1] = 0
    while q:  # 큐가 비어있지 않다면
        # 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        dist, now = heapq.heappop(q)
        # 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if distance[now] < dist:
            continue
        # 현재 노드와 연결된 다른 인접한 노드들을 확인
        for i in graph[now]:
            cost = dist + i[1]
            # 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

    # 모든 노드로 가기 위한 최단 거리를 출력
    for i in range(1, N + 1):
        if distance[i] <= K:
            answer += 1

    return answer


print(solution(5, [[1, 2, 1], [2, 3, 3], [5, 2, 2], [1, 4, 2], [5, 3, 1], [5, 4, 2]], 3))
