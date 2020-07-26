arr = [0 for i in range(10)]

A = int(input())
B = int(input())
C = int(input())

num = A*B*C

while num!=0:
    temp = num%10
    arr[temp]+=1
    num=num//10

for i in range(10):
    print(arr[i])