import heapq


def solution(A, B):
    if min(A) > max(B):
        return 0
    A.sort(reverse=True)

    B = [-i for i in B]

    heapq.heapify(B)
    count = 0
    for a in A:
        if a >= abs(B[0]):
            continue
        else:
            heapq.heappop(B)
            count += 1
    return count


print(solution([5, 1, 3, 7], [2, 2, 6, 8]))
