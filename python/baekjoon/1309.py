n = int(input())

MOD = 9901
arr = [[0] * 3 for _ in range(100001)]

arr[1][0] = 1
arr[1][1] = 1
arr[1][2] = 1

for i in range(2, n + 1):
    arr[i][0] = (arr[i - 1][0] + arr[i - 1][1] + arr[i - 1][2]) % MOD
    arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % MOD
    arr[i][2] = (arr[i - 1][0] + arr[i - 1][1]) % MOD

print(sum(arr[n]) % MOD)
