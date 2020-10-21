def countSort(arr, exp):
    n = len(arr)
    buffer = [0] * n
    count = [0] * 10

    # exp의 자릿수에 해당하는 count 증가
    for i in range(n):
        count[(arr[i] // exp) % 10] += 1

    # 누적합 구하기
    for i in range(1, 10):
        count[i] += count[i - 1]

    # 일반적인 Counting sort 과정
    for i in range(n - 1, -1, -1):
        buffer[count[(arr[i] // exp) % 10] - 1] = arr[i]
        count[(arr[i] // exp) % 10] -= 1
    for i in range(0, n):
        arr[i] = buffer[i]


def radixsort(arr):
    # arr 배열중에서 maxValue를 잡아서 어느 digit, 자릿수까지 반복하면 될지를 정한다.
    m = max(arr)

    # 최댓값을 나눴을 때, 0이 나오면 모든 숫자가 exp의 아래
    exp = 1
    while m // exp > 0:
        countSort(arr, exp)
        exp *= 10


arr = [170, 45, 75, 90, 802, 24, 2, 66]
n = len(arr)
radixsort(arr)

for i in range(n):
    print(arr[i], end=" ")
