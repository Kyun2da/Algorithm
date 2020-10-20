def SelectionSort(arr):
    length = len(arr)
    for i in range(length - 1):
        minIdx = i
        for j in range(i + 1, length):
            if arr[j] < arr[minIdx]:
                minIdx = j
        arr[minIdx], arr[i] = arr[i], arr[minIdx]
    return arr


arr = [3, 5, 2, 4, 6, 1]

print(SelectionSort(arr))
