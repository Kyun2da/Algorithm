n = int(input())

arr = [0] * 31

arr[0] = 1
for i in range(2, 31, 2):
    arr[i] = arr[i - 2] * 3
    for j in range(i - 4, -1, -2):
        arr[i] += arr[j] * 2

print(arr[n])
