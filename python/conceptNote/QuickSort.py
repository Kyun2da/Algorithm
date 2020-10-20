def partition(left, right):
    pivot = arr[(left + right) // 2]
    while left <= right:
        while arr[left] < pivot:
            left += 1
        while arr[right] > pivot:
            right -= 1
        if left <= right:
            arr[left], arr[right] = arr[right], arr[left]
            left, right = left + 1, right - 1
    return left


def quickSort(arr, left, right):
    if right <= left:
        return

    mid = partition(left, right)
    quickSort(arr, left, mid - 1)
    quickSort(arr, mid, right)


arr = [3, 5, 2, 4, 6, 1]

quickSort(arr, 0, len(arr) - 1)
print(arr)
