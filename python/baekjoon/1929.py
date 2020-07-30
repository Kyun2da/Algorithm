M, N = map(int,input().split())

prime = [False,False] + [True]*999999

for i in range(2,1000001):
    if prime[i]:
        for j in range(2*i,1000001,i):
            prime[j]=False

for i in range(M,N+1):
    if prime[i]:
        print(i)