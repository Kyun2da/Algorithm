import heapq


def solution(jobs):
    answer = 0
    # job을 요청 시간 순으로 정렬
    jobs.sort()

    heap = []  # 스케줄러
    i = 0
    time = 0
    # job이 남아있지 않을때까지 실행
    while i < len(jobs) or len(heap) != 0:
        # 현재 시간보다 이전에 들어온 요청들을 모두 스케줄러에 넣는다.
        while len(jobs) > i and time >= jobs[i][0]:
            heapq.heappush(heap, jobs[i])
            i += 1
        # 스케줄러를 수행시간이 빠른 순으로 정렬
        heap.sort(key=lambda x: x[1])
        if len(heap) != 0:
            time += heap[0][1]
            answer += time - heap[0][0]
            heap.pop(0)
        else:
            time = jobs[i][0]
    return answer // len(jobs)


print(solution([[0, 3], [1, 9], [2, 6]]))
