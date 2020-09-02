from itertools import permutations

n = int(input())

arr = [i for i in range(1, n + 1)]
ans = list(permutations(arr, n))
for i in range(len(ans)):
    for j in range(n):
        print(ans[i][j], end=' ')
    print()
