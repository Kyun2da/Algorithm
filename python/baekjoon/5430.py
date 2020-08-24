from collections import deque
import sys

T = int(sys.stdin.readline().rstrip())

for _ in range(T):
    command = sys.stdin.readline().rstrip()
    n= int(sys.stdin.readline().rstrip())
    str = sys.stdin.readline().rstrip()[1:-1].split(',')
    errorCode = False
    rCount = 0
    deq = deque()
    if n!=0:
        deq = deque(map(int,str))
    for i in range(len(command)):
        if command[i]=='R':
            rCount+=1
        elif len(deq)==0:
            errorCode=True
            break
        elif rCount%2==0:
            deq.popleft()
        else:
            deq.pop()
    if errorCode:
        print('error')
    else:
        if rCount%2==1:
            deq.reverse()
        print('[',end="")
        for i in range(len(deq)):
            print(deq[i],end="")
            if i!=len(deq)-1:
                print(',',end="")
        print(']')