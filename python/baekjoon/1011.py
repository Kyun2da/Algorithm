num = int(input())

for i in range(num):
    A,B = map(int,input().split())
    distance = B-A
    answer = 0
    repeat = 1
    start = 0
    num = 1
    while True:
        # 두번씩 repeat을 반복한다.
        for j in range(2):
            start+=repeat
            if distance<=start:
                answer = num
                break
            #print(start)
            num+=1
        if answer !=0:
            break
        repeat+=1
    print(answer)