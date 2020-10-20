def InsertionSort(arr):
    for i in range(len(arr)):
        tmp = arr[i]
        prev = i - 1
        while prev >= 0 and arr[prev] > tmp:
            arr[prev + 1] = arr[prev]
            prev -= 1
        arr[prev + 1] = tmp

    return arr

arr = [3, 5, 2, 4, 6, 1]

print(InsertionSort(arr))
