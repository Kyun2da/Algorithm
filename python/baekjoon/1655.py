import sys
import heapq

n = int(sys.stdin.readline())

# 최대힙과 최소힙으로 구현
left, right = [], []

for _ in range(n):
    k = int(sys.stdin.readline())
    # 왼쪽과 오른쪽 길이가 같으면 왼쪽에 값을 저장한다.
    if len(left) == len(right):
        heapq.heappush(left, (-k, k))
    else:
        heapq.heappush(right, (k, k))
    #오른쪽 힙값보다 왼쪽 힙값이 더크면 오른쪽과 왼쪽원소를 바꿔준다.
    if right and left[0][1] > right[0][1]:
        leftVal = heapq.heappop(left)[1]
        rightVal = heapq.heappop(right)[1]
        heapq.heappush(left, (-rightVal, rightVal))
        heapq.heappush(right, (leftVal, leftVal))

    print(left[0][1])
