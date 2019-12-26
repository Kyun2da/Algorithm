#include <cstdio>
#include <stdlib.h>
// 합병정렬은 O(nlogn)의 시간 복잡도를 가지고 있다.
// 일반적인 방법으로 이 정렬은 안정적인 방법에 속하며 분할정복 알고리즘중 하나이다.
// 폰노이만이 1945년에 개발

/*
합병정렬의 동작원리:
1. 리스트의 길이가 1이하이면 이미 정렬된 것으로 본다.
2. 분할(divide) : 정렬되지 않은 리스트를 절반으로 잘라 비슷한 크기의 두 부분으로 나눈다.
3. 정복(conquer) : 각 부분 리스트를 재귀적으로 합병 정렬을 이용해 정렬한다.
4. 결합(combine) : 두 부분 리스트를 다시 하나의 정렬된 리스트로 합병한다. 이때 정렬 결과가 임시배열에 저장된다.
5. 복사(copy) : 임시 배열에 저장된 결과를 원래 배열에 복사한다.
*/

int arr[1000001];
int* arr2;

void merge(int left, int right) //두개의 배열 (left~mid) , (mid+1~right)를 비교해 한칸씩비교하여 arr2로 걸러낸다. 걸러낸 배열의 자리수를 증가
{
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];
	}

	int tmp = i > mid ? j : i;

	while (k <= right) arr2[k++] = arr[tmp++];
	
	for (int i = left; i <= right; i++) arr[i] = arr2[i];
}

void partition(int left, int right)
{
	int mid;
	if (left < right)
	{
		//2. 분할
		mid = (left + right) / 2;

		//3. 정복
		partition(left, mid);
		partition(mid + 1, right);
		//4. 결합
		merge(left, right);
	}
}

int main()
{
	int num;
	scanf("%d", &num);
	arr2 = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);
	partition(0, num - 1);

	for (int i = 0; i < num; i++)
		printf("%d\n", arr[i]);

	return 0;
}


