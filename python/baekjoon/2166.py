import sys
import math

input = sys.stdin.readline

n = int(input())
arr = [] * n

for _ in range(n):
    arr.append(list(map(int, input().split())))
arr.append(arr[0])

a = 0
b = 0
for i in range(n):
    a += arr[i][0] * arr[i + 1][1]
    b += arr[i][1] * arr[i + 1][0]

print(abs((a - b)/2))
