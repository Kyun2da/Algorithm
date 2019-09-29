#include <cstdio>
#include <stdlib.h>
//���� ���� ( O(n^2)�� �����Ѵ�)
//���ڸ� ���� �˰��� �� �ϳ�
//�ش� ��ġ�� � ���Ҹ� �������� �����ϴ� �˰���

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