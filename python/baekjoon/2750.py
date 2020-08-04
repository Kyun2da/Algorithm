import sys

N = int(sys.stdin.readline())

arr =[]
for i in range(N):
    K = int(sys.stdin.readline())
    arr.append(K)

arr.sort()

for i in arr:
    print(i)