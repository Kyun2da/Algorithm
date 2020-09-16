arr = [[0] * 10 for _ in range(1001)]
mod = 10007

for i in range(0, 10):
    arr[1][i] = 1

for i in range(2, 1001):
    for j in range(0, 10):
        for k in range(0, j + 1):
            arr[i][j] += arr[i - 1][k] % mod

n = int(input())

print(sum(arr[n]) % mod)
