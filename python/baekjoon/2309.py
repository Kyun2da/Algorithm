from itertools import permutations

arr = []

for i in range(9):
    arr.append(int(input()))

tmp = list(permutations(arr,7))
ans = []

for candidate in tmp:
    if sum(candidate) == 100:
        ans = list(candidate)

ans.sort()
for i in ans:
    print(i)