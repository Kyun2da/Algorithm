#include <cstdio>
#include <stdlib.h>

//퀵정렬
//퀵정렬은 찰스 앤터니 리처드 호어가 개발한 정렬 알고리즘이다.
//다른원소와의 비교만으로 정렬을 수행하는 비교정렬에 속한다.
//퀵정렬은 n개의 데이터를 정렬할 때, 최악의 경우에는 O(n^2)번의 비교를 수행하고, 평균적으로 O(nlogn)번의 비교를 수행한다.
//퀵 정렬의 내부 루프는 대부분의 컴퓨터 아키텍처에서 효율적으로 작동하도록 설계되어 있고(그 이유는 메모리 참조가 지역화되어 있기 때문에 CPU 캐시의 히트율이 높아지기 때문이다.)
//대부분의 실질적인 데이터를 정렬할 때 제곱 시간이 걸릴 확률이 거의 없도록 알고리즘을 설계하는 것이 가능하다. 
//또한 매 단계에서 적어도 1개의 원소가 자기 자리를 찾게 되므로 이후 정렬할 개수가 줄어든다. 
//때문에 일반적인 경우 퀵 정렬은 다른 O(n log n) 알고리즘에 비해 훨씬 빠르게 동작한다. 
//이러한 이유로 퀵소트(빠른정렬)라는 이름의 기원이 되었다. 그리고 퀵 정렬은 정렬을 위해 O(log n)만큼의 memory를 필요로한다.

//퀵정렬은 분할정복방법을 통해 리스트를 정렬한다.
//리스트가운데서 하나의 원소를 고른다. 이렇게 고른 원소를 피벗이라한다.
//피벗 앞에는 피벗보다 값이 작은 모든 원소들이 오고 피벗 뒤에는 피벗보다 큰 값이 오도록 피벗을 기준으로 리스트를 둘로 나눈다.
// 이렇게 리스트를 둘로 나눈 것을 분할이라고 한다. 분할을 마친 후에 피벗은 더이상 움직이지 않는다.
//분할된 두 개의 작은 리스트에 대해 재귀적으로 이 과정을 반복한다. 재귀는 리스트의 크기가 0이나 1이 될 때 까지 반복한다.
//재귀 호출이 한번 진행될 때마다 최소한 하나의 원소는 최종적으로 위치가 정해지므로, 이 알고리즘은 반드시 끝난다는 것을 보장할 수 있다.

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

int main()
{
	int num;
	int* arr;
	scanf("%d", &num);
	arr = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);
	quickSort(arr, 0, num - 1);

	for (int i = 0; i < num; i++)
		printf("%d\n", arr[i]);

	return 0;
}


