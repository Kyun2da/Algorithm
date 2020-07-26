num = int(input())

for i in range(num):
    str = input()
    repeat = 0
    ans = 0
    for a in str:
        if a=='O':
            ans+=repeat+1
            repeat+=1
        else:
            repeat=0
    print(ans)

