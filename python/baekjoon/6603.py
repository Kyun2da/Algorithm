from itertools import combinations

while True:
    tmp = list(map(int, input().split()))
    if tmp[0] == 0:
        break
    n = tmp[0]
    arr = tmp[1:]
    candidate = combinations(arr, 6)
    for x in candidate:
        for it in x:
            print(it, end=" ")
        print()
    print()