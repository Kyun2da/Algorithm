oddSum = 0
minOdd = 1e9
for _ in range(7):
    n = int(input())
    if n % 2 == 1:
        oddSum += n
        minOdd = min(minOdd, n)

if oddSum == 0:
    print(-1)
else:
    print(oddSum)
    print(minOdd)
