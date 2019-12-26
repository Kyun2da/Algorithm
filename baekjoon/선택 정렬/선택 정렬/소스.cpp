#include <cstdio>
#include <stdlib.h>
//선택 정렬 ( O(n^2)을 만족한다)
//제자리 정렬 알고리즘 중 하나
//해당 위치에 어떤 원소를 넣을지를 결정하는 알고리즘

void Selection_Sort(int arr[], int len)
{
	int i, j, indexMin, temp;
	
	for (i = 0; i < len - 1; i++)
	{
		indexMin = i;
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[indexMin])
			{
				indexMin = j;
			}
		}
		temp = arr[indexMin];
		arr[indexMin] = arr[i];
		arr[i] = temp;
	}
}


int main()
{
	int num;
	int* arr;
	scanf("%d", &num);
	arr = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);
	Selection_Sort(arr, num);

	for (int i = 0; i < num; i++)
		printf("%d\n", arr[i]);

	return 0;
}