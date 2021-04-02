n = int(input())

arr = list(map(int, input().split()))
maxNum = int(input())

left = 0
right = max(arr)

while left <= right:
    mid = (left + right) // 2

    tmp = 0
    for x in arr:
        if mid >= x:
            tmp += x
        else:
            tmp += mid

    if tmp <= maxNum:
        left = mid + 1
    else:
        right = mid - 1

print(right)
