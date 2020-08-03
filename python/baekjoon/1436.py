def isEndingNum(i):
    num = 0
    while i!=0:
        if i%10==6:
            num+=1
        else:
            num=0
        if num >= 3:
            return True
        i//=10
    return False

N = int(input())

i=666
ans = 0
while True:
    if isEndingNum(i):
        ans+=1
    if ans==N:
        break
    i+=1

print(i)