import sys

input = sys.stdin.readline

n = int(input())

arr = []

for _ in range(n):
    name, korean, math, english = map(str, input().split())
    arr.append([name, int(korean), int(math), int(english)])

arr.sort(key=lambda x: (-int(x[1]), int(x[2]), -int(x[3]), x[0]))

for x in arr:
    print(x[0])
