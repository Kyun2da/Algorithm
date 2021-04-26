import sys

n, c = map(int, input().split())

arr = []
for _ in range(n):
    arr.append(int(sys.stdin.readline()))

arr.sort()

start = 1
end = arr[-1] - arr[0]

maxVal = 0
while start <= end:
    mid = (start + end) // 2
    idx, result = 0, 1
    for i in range(1, len(arr)):
        if arr[idx] + mid <= arr[i]:
            result += 1
            idx = i
    if result < c:
        end = mid - 1
    elif result >= c:
        maxVal = mid
        start = mid + 1

print(maxVal)
