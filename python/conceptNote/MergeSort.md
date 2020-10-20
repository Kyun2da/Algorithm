# 병합 정렬(Merge Sort)

------

본 문서는 [Tech Interview](https://gyoogle.dev/blog/algorithm/Merge%20Sort.html)를 파이썬 버전으로 바꾼 것 입니다.



합병 정렬이라고도 부르며, 분할 정복 방법을 통해 구현

***분할 정복이란?***

> 큰 문제를 작은 문제 단위로 쪼개면서 해결해나가는 방식

빠른 정렬로 분류되며, 퀵소트와 함께 많이 언급되는 정렬 방식이다.

퀵소트와는 반대로 `안정 정렬`에 속함

**시간복잡도**

|   평균   |   최선   |   최악   |
| :------: | :------: | :------: |
| O(nlogn) | O(nlogn) | O(nlogn) |

요소를 쪼갠 후, 다시 합병시키면서 정렬해나가는 방식으로, 쪼개는 방식은 퀵정렬과 유사

- mergeSort

```python
def mergeSort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    leftArr = arr[:mid]
    rightArr = arr[mid:]
    leftArr = mergeSort(leftArr)
    rightArr = mergeSort(rightArr)
    return merge(leftArr, rightArr)
```

정렬 로직에 있어서 merge() 메소드가 핵심

*퀵소트와의 차이점*

> 퀵정렬 : 우선 피벗을 통해 정렬(partition) → 영역을 쪼갬(quickSort)
>
> 합병정렬 : 영역을 쪼갤 수 있을 만큼 쪼갬(mergeSort) → 정렬(merge)

- merge()

```java
def merge(left, right):
    result = []
    while len(left) > 0 or len(right) > 0:
        if len(left) > 0 and len(right) > 0:
            if left[0] <= right[0]:
                result.append(left[0])
                left = left[1:]
            else:
                result.append(right[0])
                right = right[1:]
        elif len(left) > 0:
            result.append(left[0])
            left = left[1:]
        elif len(right) > 0:
            result.append(right[0])
            right = right[1:]
    return result
```

이미 **합병의 대상이 되는 두 영역이 각 영역에 대해서 정렬이 되어있기 때문**에 단순히 두 배열을 **순차적으로 비교하면서 정렬할 수가 있다.**

★★★**합병정렬은 순차적**인 비교로 정렬을 진행하므로, **LinkedList의 정렬이 필요할 때 사용하면 효율적**이다.★★★

*LinkedList를 퀵정렬을 사용해 정렬하면?*

> 성능이 좋지 않음
>
> 퀵정렬은, 순차 접근이 아닌 **임의 접근이기 때문**

**LinkedList는 삽입, 삭제 연산에서 유용**하지만 **접근 연산에서는 비효율적**임

따라서 임의로 접근하는 퀵소트를 활용하면 오버헤드 발생이 증가하게 됨

> 배열은 인덱스를 이용해서 접근이 가능하지만, LinkedList는 Head부터 탐색해야 함
>
> 배열[O(1)] vs LinkedList[O(n)]