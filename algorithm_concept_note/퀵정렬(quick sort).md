# 퀵정렬(quick sort)

### 개념

- '**찰스 앤터니 리처드 호어**(Charles Antony RIchard Hoare)'가 개발한 정렬 알고리즘
- 다른 원소와의 비교만으로 정렬을 수행하는 **비교 정렬**에 속한다.
- 퀵 정렬은 n개의 데이터를 정렬할 때, **최악의 경우에는 O(n^2)번**의 비교를 수행하고 평균적으로  **O(nlogn) 번**의 비교를 수행한다.
- 퀵 정렬의 내부 루프는 대부분의 컴퓨터 아키텍쳐에서 효율적으로 작동하도록 설계되어 있으며, 대부분의 실질적인 데이터를 정렬할 때 `제곱시간이 걸릴 확률이 거의 없도록 설계하는 것이 가능`하다.
- 퀵 정렬은 정렬을 위해 **O(nlogn)만큼의 memory**를 필요로한다.
- 원소들 중에 같은 값이 있는 경우 정렬 순서와 달라질 수 있어 **불안정 정렬**에 속한다.

### 정렬 원리

퀵 정렬은 **분할 정복** 방법을 통해 리스트를 정렬한다.

1.  리스트 가운데서  하나의 원소를 고른다. 이렇게 고른 원소를 **피벗(pivot)**이라고 한다.
2.  피벗 앞에는 피벗보다 값이 작은 모든 원소들이 오고, 피벗 뒤에는 피벗보다 값이 큰 모든 원소들이 오도록 피벗을 기준으로 리스트를 둘로 나눈다. 이것을 **분할**이라고 한다. 분할을 마친 뒤, 피벗은 더 이상 움직이지 않는다.
3. 분할된 두 개의 작은 리스트에 대해 **재귀**적으로 이 과정을 반복한다. 재귀는 리스트의 크기가 0이나 1이 될 때까지 반복된다.

재귀 호출이 한번 진행될 때마다 최소한 하나의 원소는 최종적으로 위치가 정해지므로, 이 알고리즘은 반드시 끝난다는 것을 보장할 수 있다.

![퀵 정렬](https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif)

### 퀵 정렬 예제

퀵정렬은 임의의 pivot값을 기준으로 pivot의 좌측에는 pivot보다 작은값을 두고 우측에는 pivot보다 큰 값을 두고자 한다.

피벗은 p, 리스트 왼쪽 끝과 오른쪽 끝에서 시작한 인덱스들을 i,j라고 하자

```
5 - 3 - 7 - 6 - 2 - 1 - 4
					    p
```

리스트 왼쪽에 있는 i 위치의 값이 피벗 값보다 크고, 오른쪽에 있는 j위치의 값은 피벗 값보다 작으므로 둘을 교환한다.

```
5 - 3 - 7 - 6 - 2 - 1 - 4
i                   j   p
1 - 3 - 7 - 6 - 2 - 5 - 4
i                   j   p
```

j 위치의 값이 피벗 값보다 작지만, i 위치의 값도 피벗값보다 작으므로 교환하지 않는다.

```
1 - 3 - 7 - 6 - 2 - 5 - 4 
    i           j       p 
```

i위치를 피벗 값보다 큰 값이 나올 때 까지 진행해 j 위치의 값과 교환한다.

```
1 - 3 - 7 - 6 - 2 - 5 - 4 
        i       j       p 
1 - 3 - 2 - 6 - 7 - 5 - 4 
        i       j       p 
```

i위치가 j 위치보다 커지면, i 위치의 값과 피벗 값을 교환한다.

```
1 - 3 - 2 - 6 - 7 - 5 - 4 
                        p 
1 - 3 - 2 - 4 - 7 - 5 - 6 
            p       
```

피벗 값 좌우의 리스트에 대해 각각 퀵 정렬을 재귀적으로 수행한다.

```
1 - 3 - 2       7 - 5 - 6
1 - 2 - 3       5 - 6 - 7
```

완성된 리스트는 다음과 같다.

```
1 - 2 - 3 - 4 - 5 - 6 - 7
```

### 소스코드

```c++
void quickSort(int arr[], int left, int right)
{
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];
	int temp;
	do
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}
```

[총 소스코드](https://github.com/Kyun2da/Algorithm/blob/master/%EB%B0%B1%EC%A4%80%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/%ED%80%B5%20%EC%A0%95%EB%A0%AC/%ED%80%B5%20%EC%A0%95%EB%A0%AC/%EC%86%8C%EC%8A%A4.cpp)

### Reference

[나무위키](https://ko.wikipedia.org/wiki/퀵_정렬)

### Bonus

[![Video Label](http://img.youtube.com/vi/ywWBy6J5gz8/0.jpg)](https://youtu.be/ywWBy6J5gz8?t=0s) Video Label



