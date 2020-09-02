from itertools import permutations

n = int(input())

arr = list(map(int, input().split()))

permuArr = list(permutations(arr, n))

ans = float('-inf')
for i in range(len(permuArr)):
    total = 0
    for j in range(0, n - 1):
        total += abs(permuArr[i][j] - permuArr[i][j + 1])
    if ans < total:
        ans = total

print(ans)