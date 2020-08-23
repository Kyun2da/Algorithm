import sys

K = int(input())

arr = []

for _ in range(K):
    N = int(sys.stdin.readline().rstrip())
    if N == 0:
        arr.pop()
    else:
        arr.append(N)

print(sum(arr))
