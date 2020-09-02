def binarySearch(arr, target, start, end):
    global ans
    while start <= end:
        mid = (start + end) // 2
        total = 0
        for x in arr:
            total += max(x - mid, 0)
        # 떡이 많이 나온다면 좀 더잘라야함
        if total >= target:
            ans = mid
            start = mid + 1
        # 떡이 조금나오면 조금 잘라야함
        else:
            end = mid -1


n, m = list(map(int, input().split()))

arr = list(map(int, input().split()))
ans = 0
binarySearch(arr, m, 0, arr[-1])

print(ans)