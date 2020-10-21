# counting sort 구현
def countingSort(array, max):
    # counting array 생성
    countingArr = [0] * (max + 1)

    # countingArr에 inputArr내 원소의 빈도수 담기
    for i in array:
        countingArr[i] += 1

    # countingArr 업데이트.
    for i in range(max):
        countingArr[i + 1] += countingArr[i]

    # outputArr 생성
    outputArr = [-1] * len(array)

    # outputArr에 정렬하기(counting array를 참조)
    for i in array:
        outputArr[countingArr[i] - 1] = i
        countingArr[i] -= 1
    return outputArr


arr = [1, 4, 2, 5, 3, 6, 3, 5]

print(countingSort(arr, max(arr)))
