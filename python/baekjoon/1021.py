import sys
from collections import deque

N, M = map(int,input().split())

arr = deque(map(int,sys.stdin.readline().rstrip().split()))
deq = deque(i for i in range(1,N+1))
ans = 0
while True:
    if len(arr)==0:
        break
    idx = deq.index(arr[0])

    if arr[0] == deq[0]:
        deq.popleft()
        arr.popleft()
    else:
        # 왼쪽에서 자르는게 더유리한 경우
        if len(deq)//2 >= idx:
            while True:
                num = deq.popleft()
                deq.append(num)
                ans+=1
                if deq[0]==arr[0]:
                    deq.popleft()
                    arr.popleft()
                    break
        else:
            while True:
                num = deq.pop()
                deq.appendleft(num)
                ans += 1
                if deq[0]==arr[0]:
                    deq.popleft()
                    arr.popleft()
                    break
print(ans)