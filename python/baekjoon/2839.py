num = int(input())

res = 0

while num!=0:
    if num%5==0:
        num-=5
        res+=1
    elif num%3==0:
        num-=3
        res+=1
    elif num>5:
        num-=5
        res+=1
    else:
        res = -1
        break

print(res)