prime = [False,False] + [True]*299999

for i in range(2,300001):
    if prime[i]:
        for j in range(2*i,300001,i):
            prime[j]=False

while True:
    num = int(input())
    answer = 0
    if num==0:
        break
    for i in range(num+1,num*2+1):
        if prime[i]:
            answer+=1
    print(answer)