import sys

input = sys.stdin.readline

n = input().rstrip()
arr = []

for i in range(len(n)):
    arr.append(n[i:])

arr.sort()

for x in arr:
    print(x)
