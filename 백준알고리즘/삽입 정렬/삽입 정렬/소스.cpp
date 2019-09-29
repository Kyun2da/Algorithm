#include <cstdio>
#include <stdlib.h>
//삽입 정렬 ( O(n^2)을 만족한다)
//제자리 정렬 알고리즘 중 하나
//해당 원소를 어느 위치에 넣을거냐 하는 알고리즘
//선택정렬이나 거품정렬과 같은 알고리즘보다 빠르며 안정적이다.

void Insertion_Sort(int arr[], int len)
{
	int i, j, remember;
	for (i = 1; i < len; i++)
	{
		remember = arr[i]; //삽입될 숫자를 기억해 놓는다.

		//remember보다 arr[j]값이 크면 arr[j]를 arr[j+1]로 이동
		for (j = i - 1; j >= 0 && arr[j] > remember; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = remember;
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
	Insertion_Sort(arr, num);

	for (int i = 0; i < num; i++)
		printf("%d\n", arr[i]);

	return 0;
}