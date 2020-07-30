prime = [False,False] + [True]*9999

for i in range(2,10001):
    if prime[i]:
        for j in range(2*i,10001,i):
            prime[j]=False

T = int(input())

for i in range(T):
    N = int(input())
    minNum = float('inf')
    answer1 = 0
    answer2 = 0
    for j in range(N//2+1):
        if prime[j] and prime[N-j] and minNum>N-j*2:
            minNum=N-j*2
            answer1 = j
            answer2 = N-j
    print("%d %d"%(answer1,answer2))
