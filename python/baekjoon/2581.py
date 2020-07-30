M = int(input())
N = int(input())

prime = [False,False] + [True]*9999
answer= 0
minNum = float('inf')

for i in range(2,10001):
    if prime[i]:
        for j in range(2*i,10001,i):
            prime[j]=False

for i in range(M,N+1):
    if prime[i]:
        answer+=i
        if i < minNum:
            minNum = i

if answer ==0:
    print(-1)
else:
    print(answer)
    print(minNum)