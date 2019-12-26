#include <cstdio>
#include <stdlib.h>
//���� ���� ( O(n^2)�� �����Ѵ�)
//���� ��� ��Ȳ���� �־��� ��Ȳ�� �����ش�.
//������ �̹� ���ĵ� �ڷῡ���� �ѹ��� ���� �Ǳ� ������ �ּ��� ������ �����ش�

void Bubble_Sort(int a[], int len) //ex. 54321 �� 12345�� ������������ , �� �ں��� ū����� ���ĵȴ�
{
	for (int i = len - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
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
	Bubble_Sort(arr, num);

	for (int i = 0; i < num; i++)
		printf("%d\n", arr[i]);

	return 0;
}