import sys

t = int(input())

arr = [0] * 1000001
arr[1], arr[2], arr[3] = 1, 2, 4

for i in range(4, 1000001):
    arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]) % 1000000009

for _ in range(t):
    n = int(sys.stdin.readline())
    print(arr[n])