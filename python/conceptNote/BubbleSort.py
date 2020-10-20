'''
제외될 원소의 갯수를 의미한다.
1회전이 끝난 후, 배열의 마지막 위치에는 가장 큰 원소가 위치하기 때문에 하나씩 증가시켜준다.
원소를 비교할 index를 뽑을 반복문이다.
j는 현재 원소를 가리키고, j-1은 이전 원소를 가리키게 되므로, j는 1부터 시작하게 된다.
현재 가르키고 있는 두 원소의 대소를 비교한다.
해당 코드는 오름차순 정렬이므로 현재 원소보다 이전 원소가 더 크다면 이전 원소가 뒤로 가야하므로 서로 자리를 교환해준다.
'''

def bubbleSort(arr):
    length = len(arr)
    for i in range(length):
        for j in range(1, length - i):
            if arr[j - 1] > arr[j]:
                arr[j - 1], arr[j] = arr[j], arr[j - 1]
    return arr


arr = [3, 5, 2, 4, 6, 1]

print(bubbleSort(arr))
