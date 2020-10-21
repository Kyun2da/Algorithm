# 계수 정렬(Counting Sort)

------



### Comparison Sort

> N개 원소의 배열이 있을 때, 이를 모두 정렬하는 가짓수는 N!임
>
> 따라서, Comparison Sort를 통해 생기는 트리의 말단 노드가 N! 이상의 노드 갯수를 갖기 위해서는, 2^h >= N! 를 만족하는 h를 가져야 하고, 이 식을 h > O(nlgn)을 가져야 한다. (h는 트리의 높이,,, 즉 Comparison sort의 시간 복잡도임)

이런 O(nlgn)을 줄일 수 있는 방법은 Comparison을 하지 않는 것



### Counting Sort 과정

시간 복잡도 : O(n + k) -> k는 배열에서 등장하는 최대값

공간 복잡도 : O(k) -> k만큼의 배열을 만들어야 함.

Counting이 필요 : 각 숫자가 몇 번 등장했는지 센다.



### 소스 코드

```python
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

```



- 사용 : 정렬하는 숫자가 특정한 범위 내에 있을 때 사용

  (Suffix Array 를 얻을 때, 시간복잡도 O(nlgn)으로 얻을 수 있음.)

- 장점 : O(n) 의 시간복잡도

- 단점 : 배열 사이즈 N 만큼 돌 때, 증가시켜주는 Counting 배열의 크기가 큼.

  (메모리 낭비가 심함)