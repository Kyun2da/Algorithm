import sys

N = 1000001

arr = [True] * (N + 1)
for i in range(2, len(arr) // 2 + 1):
    if arr[i]:
        for j in range(i + i, N, i):
            arr[j] = False

arr[0] = False
arr[1] = False

while True:
    n = int(sys.stdin.readline())
    if n == 0:
        break
    for i in range(n // 2 + 1):
        if arr[i] and arr[n - i]:
            print("%d = %d + %d" % (n, i, n - i))
            break
        if i == n // 2:
            print("Goldbach's conjecture is wrong.")
