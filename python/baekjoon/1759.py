from itertools import combinations

vowels = ['a', 'e', 'i', 'o', 'u']

l, c = map(int, input().split())

arr = list(map(str, input().split()))

arr.sort()

ans = combinations(arr, l)

for x in ans:
    zanum = 0
    monum = 0
    for alpha in x:
        if alpha in vowels:
            monum += 1
        else:
            zanum += 1
    if zanum >= 2 and monum >= 1:
        print("".join(x))
