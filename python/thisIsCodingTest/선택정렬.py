# 선택정렬의 복잡도는 O(N^2)

arr = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

for i in range(len(arr)):
    minIndex = i  # 가장 작은 원소의 인덱스
    for j in range(i + 1, len(arr)):
        if arr[minIndex] > arr[j]:
            minIndex = j
    arr[i], arr[minIndex] = arr[minIndex], arr[i]  # 스왑

print(arr)