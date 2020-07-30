T = int(input())

for i in range(T):
    x1,y1,r1,x2,y2,r2 = map(int,input().split())
    distance = pow(pow(x2-x1,2)+pow(y2-y1,2),1/2)
    #두 원이 서로 같을 때
    if distance==0 and r1==r2:
        print(-1)
    # 두 원이 서로 안만날 때(한 원이 포함할때 혹은 서로 다른공간에 있을때)
    elif distance > r1+r2:
        print(0)
    elif distance + r1 < r2 or distance + r2 < r1:
        print(0)
    #두 원이 밖에서 서로 한점에서 만날 때(외접)
    elif distance == r1+r2:
        print(1)
    #두 원이 안에서 서로 한점에서 만날 때(내접)
    elif  distance+r2 == r1 or distance+r1==r2:
        print(1)
    # 두 원이 서로 만나는 점이 두개일 때
    else:
        print(2)
