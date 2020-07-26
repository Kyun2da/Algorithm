def hansu(n):
    if n <= 99:
        return True
    elif n<1000:
        if n//100 - n//10%10 == n//10%10 - n%10:
            return True
        else:
            return False
    else:
        return False
    return True

num = int(input())
res = 0
for i in range(1,num+1):
    if hansu(i):
        res +=1

print(res)