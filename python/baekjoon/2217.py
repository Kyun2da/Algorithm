n = int(input())

arr = []
for _ in range(n):
    arr.append(int(input()))

arr.sort()

maxans = 0

sum1 = 0
idx = 0
for i in range(len(arr) - 1, -1, -1):
    idx += 1
    maxans = max(maxans, arr[i] * idx)

print(maxans)
