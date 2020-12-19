arr = list(map(int, input()))

jariSum = sum(arr)

if jariSum % 3 == 0:
    arr.sort(reverse=True)
    if arr[-1] == 0:
        print(''.join(map(str, arr)))
    else:
        print(-1)
else:
    print(-1)
