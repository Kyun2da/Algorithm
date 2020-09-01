arr = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]

def quickSort(arr):
    # 리스트가 하나 이하의 원소만을 담고 있다면 종료
    if len(arr) <= 1:
        return arr

    pivot = arr[0]  # 피벗은 첫 번째 원소
    tail = arr[1:]  # 피벗을 제외한 리스트

    leftSide = [x for x in tail if x <= pivot]  # 분할된 왼쪽 부분
    rightSide = [x for x in tail if x > pivot]  # 분할된 오른쪽 부분

    # 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬을 수행하고, 전체리스트를 반환
    return quickSort(leftSide) + [pivot] + quickSort(rightSide)


print(quickSort(arr))
