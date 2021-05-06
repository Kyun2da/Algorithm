import sys

input = sys.stdin.readline

n, m = map(int, input().split())

arr = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

arr.extend(arr2)

arr.sort()

print(" ".join(map(str, arr)))
