#include <cstdio>
#include <stdlib.h>
//���� ���� ( O(n^2)�� �����Ѵ�)
//���ڸ� ���� �˰��� �� �ϳ�
//�ش� ���Ҹ� ��� ��ġ�� �����ų� �ϴ� �˰���
//���������̳� ��ǰ���İ� ���� �˰��򺸴� ������ �������̴�.

void Insertion_Sort(int arr[], int len)
{
	int i, j, remember;
	for (i = 1; i < len; i++)
	{
		remember = arr[i]; //���Ե� ���ڸ� ����� ���´�.

		//remember���� arr[j]���� ũ�� arr[j]�� arr[j+1]�� �̵�
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