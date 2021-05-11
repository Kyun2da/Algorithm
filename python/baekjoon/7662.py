import sys
import heapq

input = sys.stdin.readline

t = int(input())

for _ in range(t):

    n = int(input())

    max_heap = []
    min_heap = []
    vis = [0] * 1000001
    for i in range(n):
        cmd, num = map(str, input().split())
        num = int(num)

        if cmd == 'I':
            heapq.heappush(max_heap, [-num, i])
            heapq.heappush(min_heap, [num, i])
        else:
            # 최대 힙 삭제
            if num == 1:
                while max_heap:
                    _, max_idx = heapq.heappop(max_heap)
                    if vis[max_idx] == 0:
                        vis[max_idx] = 1
                        break
            else:
                while min_heap:
                    _, min_idx = heapq.heappop(min_heap)
                    if vis[min_idx] == 0:
                        vis[min_idx] = 1
                        break
        # print('삽입' if cmd == 'I' else '삭제')
        # print(max_heap)
        # print(min_heap)
        # print('-----------------------------')

    while max_heap and vis[max_heap[0][1]]:
        heapq.heappop(max_heap)
    while min_heap and vis[min_heap[0][1]]:
        heapq.heappop(min_heap)

    if max_heap:
        print(-max_heap[0][0], min_heap[0][0])
    else:
        print('EMPTY')
