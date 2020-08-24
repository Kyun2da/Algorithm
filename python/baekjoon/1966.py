from collections import deque
import sys

T = int(input())

for _ in range(T):
    N, M = map(int,sys.stdin.readline().rstrip().split())
    deq = deque(map(int, sys.stdin.readline().rstrip().split()))
    idx = deque(i for i in range(N))
    ans = 0
    while True:
        if max(deq)==deq[0]:
            ans+=1
            if idx[0] == M:
                break
            deq.popleft()
            idx.popleft()
        else:
            num1 = deq.popleft()
            num2 = idx.popleft()
            deq.append(num1)
            idx.append(num2)
    print(ans)



