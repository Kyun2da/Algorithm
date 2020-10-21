def solve():
    arr = [230, 10, 60, 550, 40, 220, 20]
    heapSort(arr)
    for i in range(len(arr)):
        print(arr[i], end=" ")


def heapify(arr, n, i):
    p = i
    l = i * 2 + 1
    r = i * 2 + 2
    if l < n and arr[p] < arr[l]:
        p = l
    if r < n and arr[p] < arr[r]:
        p = r
    if i != p:
        arr[p], arr[i] = arr[i], arr[p]
        heapify(arr, n, p)


def heapSort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, -1, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)


solve()
