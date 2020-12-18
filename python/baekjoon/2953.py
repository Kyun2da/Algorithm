arr = []

maxVal = 0
idx = None

for i in range(5):
    arr.append(list(map(int, input().split())))
    if sum(arr[i]) > maxVal:
        idx = i
        maxVal = sum(arr[i])

print(idx + 1, maxVal)
