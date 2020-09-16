arr = [[0] * 3 for _ in range(91)]

arr[1][1] = 1
for i in range(2, 91):
    arr[i][0] = arr[i - 1][0] + arr[i - 1][1]
    arr[i][1] = arr[i - 1][0]

n = int(input())

print(sum(arr[n]))
