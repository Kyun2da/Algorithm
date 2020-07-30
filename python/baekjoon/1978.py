num = int(input())
answer =0
prime = [False,False] + [True]*999

#에라토스테네스의 체 이용
for i in range(2,1001):
    if prime[i]:
        for j in range(2*i, 1001, i):
            prime[j]=False

# 주어진 수가 소수인지 판별
temp = list(map(int,input().split()))
for i in temp:
    if prime[i]:
        answer+=1

print(answer)
