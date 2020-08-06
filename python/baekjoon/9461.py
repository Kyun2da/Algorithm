import sys

T = int(sys.stdin.readline())

arr = [0,1,1,1,2,2]

for i in range(6,101):
    arr.append(arr[i-1]+arr[i-5])

for i in range(T):
    N = int(sys.stdin.readline())
    print(arr[N])