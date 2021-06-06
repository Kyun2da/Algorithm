import sys
import heapq

input = sys.stdin.readline

n, k = map(int, input().split())

# 보석을 힙에 넣는다.
gems = []
for _ in range(n):
    weight, value = map(int, input().split())
    heapq.heappush(gems, [weight, value])

# 가방을 힙에 넣는다.
bags = []
for _ in range(k):
    heapq.heappush(bags, int(input()))

answer = 0
tmp = []

# 들어갈 수 있는 무게가 작은 가방부터 넣을 수 있는 보석을 찾는다.
for _ in range(k):
    bag = heapq.heappop(bags)

    # 보석이 존재하고 가방안에 들어갈 수 있는 보석이 있을 때까지 임시 힙에 넣는다.
    while gems and bag >= gems[0][0]:
        weight, value = heapq.heappop(gems)
        heapq.heappush(tmp, -value) # 들어갈 수 있는 최대의 값이 루트가 되게 최대힙 구성하여 넣는다.

    if tmp:
        answer -= heapq.heappop(tmp)
    elif not gems:
        break

print(answer)
