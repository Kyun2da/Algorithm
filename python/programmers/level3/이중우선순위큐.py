from heapq import heappush, heappop


def solution(operations):
    maxHeap = []
    minHeap = []

    for operation in operations:
        if operation == 'D 1':
            if maxHeap:
                heappop(maxHeap)
                if maxHeap == [] or -maxHeap[0] < minHeap[0]:
                    minHeap = []
                    maxHeap = []
        elif operation == 'D -1':
            if minHeap:
                heappop(minHeap)
                if minHeap == [] or -maxHeap[0] < minHeap[0]:
                    maxHeap = []
                    minHeap = []
        else:
            num = int(operation[2:])
            heappush(maxHeap, -num)
            heappush(minHeap, num)

    if minHeap == []:
        return [0, 0]

    return [-heappop(maxHeap), heappop(minHeap)]
